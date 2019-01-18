// fabao.c

#include <weapon.h>
#include <armor.h>
#include <ansi.h>

inherit EQUIP;
inherit F_SAVE;
inherit F_BACKUP;

void create()
{
	seteuid(0);	
	set_name("���Ʒ������", ({ "fabao object", "fabao", "object" }) );
	setup();
}

void init()
{
	add_action("do_charge", "improve");
	add_action("do_charge", "charge");
	add_action("do_charge", "recharge");
}

void reset()
{
	if( !environment() ||  //mon 2/4/98
		query("owner_id") != getuid(environment()) )  
	{
		destruct(this_object());
		return;
	}
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id, series;

	id = query("owner_id");
	series = query("series_no");
	if( !id || !series) return 0;

	return sprintf(DATA_DIR "fabao/%c/%s-%s", id[0], id, series);
}

int save()
{
	//is this needed?...
	if( query("equipped") )   
	{
		write("������·������ܴ��档\n");
		return 0;
	}
	return ::save();
}

void setup()
{
	::setup();
}

int query_unique()  { return 1; }

string status_bar(int max, int current, string color)
{//note: the color string must be things like HIB, HIW, ...etc.
	int i;
	string status = color;

	if( max <=0 ) return " ";

        if( max > 50 ) max = 50;
	if( current > max ) current = max;

	for(i=1; i<=max; i++)
	{
		if( i <= current ) status += "��";
		else status += "��";
	}
   
	status += NOR;

	return status;   
}

string show_status()
{
	string status = (string)query("name")+"����״̬��\n";
	
	if( query("series_no") == "1" ) //weapon
	{
		status += " <��Ѫ�˺���> " + status_bar(query("fabao/max_attack_qi"), query_temp("fabao/attack_qi"), RED) + "\n";
		status += " <�����˺���> " + status_bar(query("fabao/max_attack_shen"), query_temp("fabao/attack_shen"), BLU) + "\n";
	}

	else //armor
	{
		status += " <��Ѫ������> " + status_bar(query("fabao/max_defense_qi"), query_temp("fabao/defense_qi"), RED) + "\n";
		status += " <���񱣻���> " + status_bar(query("fabao/max_defense_shen"), query_temp("fabao/defense_shen"), BLU) + "\n";
		status += " <������ȡ��> " + status_bar(query("fabao/max_defense_shou"), query_temp("fabao/defense_shou"), HIY) + "\n";	
	}

	return status;
}

//to actually use the fabao as a powerful tool, players need to charge it.
//each time let the player fill one square.
int do_charge(string arg)
{
	object me= this_player();
	object fabao_ob= this_object();
	int cost = 100;//now fix cost as 100, both fali and neili
        int delay_factor = 50;//actually delay is cost/delay_factor...in unit of second.
	
	if( me->is_busy()
	|| me->is_fighting()
	|| me->query_temp("pending/exercising"))
		return notify_fail("����æ���أ�����\n");
        
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") )
		return notify_fail("���ﲻ�����������ĵط���\n");

	if( !arg || !fabao_ob->id(arg) ) return notify_fail("��������ʲô������\n");
	
	if( (int)me->query("mana") < 3*cost ) //maybe used to charge 3 parameters.
		return notify_fail("��Ŀǰ�ķ���̫�ͣ���������������\n");

	if( (int)me->query("force") < 3*cost ) //maybe used to charge 3 parameters.
		return notify_fail("��Ŀǰ������̫�ͣ���������������\n");

	if( query("series_no")=="1" )//weapon
	{
		if( query_temp("fabao/attack_qi") >= query("fabao/max_attack_qi") )
			write(query("name")+"����Ѫ�˺����������״̬��\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N���������дʣ��Է������Լ�������������ע��$n֮�С�\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "attack_qi");
		}

		if( query_temp("fabao/attack_shen") >= query("fabao/max_attack_shen") )
			write(query("name")+"�ľ����˺����������״̬��\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N���������дʣ����������Լ��ķ���������ע��$n֮�С�\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "attack_shen");
		}

		return 1;
	}

	else //armor
	{
		if( query_temp("fabao/defense_qi") >= query("fabao/max_defense_qi") )
			write(query("name")+"����Ѫ�������������״̬��\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N���������дʣ��Է������Լ�������������ע��$n֮�С�\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_qi");
		}

		if( query_temp("fabao/defense_shen") >= query("fabao/max_defense_shen") )
			write(query("name")+"�ľ��񱣻����������״̬��\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N���������дʣ����������Լ��ķ���������ע��$n֮�С�\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_shen");
		}

		if( query_temp("fabao/defense_shou") >= query("fabao/max_defense_shou") )
			write(query("name")+"�ķ�����ȡ���������״̬��\n");
		else 
		{
			me->add("force", -cost);
			me->add("mana", -cost);
			message_vision("$N���������дʣ����Լ��ķ������������㣬������ע��$n֮�С�\n", me, fabao_ob);
			me->start_busy(cost/delay_factor);
			call_out("charged", cost/delay_factor, me, "defense_shou");
		}

		return 1;
	}

}

void charged(object me, string type)
{
	string property, max;
	property = "fabao/"+type;
	max = "fabao/max_"+type;

	if( query_temp(property) >= query(max) ) return;
        add_temp(property, 10);
	//save();//do not save...use temp now.
	message_vision("\nֻ��$nͻȻ�ų����ϼ�⣬$N��¶ϲɫ������������һ������\n", me, this_object());
	return;
}

//this function calculate, when a damage comes, how the fabao reduce it.
//the returned value is the damage left.
int protect_qi(int damage)
{
	int i, square;

	int def_unit = 20;
	//this is the damage each square can reduce.
	//currently it is fix...
	//can also use query("fabao/def_unit") if set it somewhere, not implemented yet.

	if( damage <= 0 ) return 0;

	square = query_temp("fabao/defense_qi");
	if( square == 0 ) return damage;

	i = damage/def_unit;

	if( i >= square )
	{//more damage
		set_temp("fabao/defense_qi",  0);
		//save();
		return damage - square*def_unit;
	}
	else
	{//more protect potential.
		set_temp("fabao/defense_qi", square-i);
		//save();
		return 0;
	}
}

int protect_shen(int damage)
{
	int i, square;

	int def_unit = 20;
	//this is the damage each square can reduce.
	//currently it is fix...
	//can also use query("fabao/def_unit") if set it somewhere, not implemented yet.

	if( damage <= 0 ) return 0;

	square = query_temp("fabao/defense_shen");
	if( square == 0 ) return damage;

	i = damage/def_unit;

	if( i >= square )
	{//more damage
		set_temp("fabao/defense_shen",  0);
		//save();
		return damage - square*def_unit;
	}
	else
	{//more protect potential.
		set_temp("fabao/defense_shen", square-i);
                //save();
		return 0;
	}
}

int ji(string target_id)
{
        int a_dx, a_exp, a_fali, a_enchant;
        int d_dx, d_exp, d_fali, d_enchant;
        int d_fabao_power, a_fabao_power;
        int damage;
        string hit_msg;
        int i, j;
        
        object fabao = this_object();
        object attacker = this_player();
        string fabao_name=fabao->query("name");
        object where=environment(attacker);
        object target;
        object *inv;
        object d_fabao1, d_fabao2;

        if (!target_id)
                return notify_fail("�����˭��"+fabao_name+"��\n");

        target=present(target_id, environment(attacker));
        if( !target )
                return notify_fail("��Ĺ���Ŀ�겻�����\n");

        if( attacker->is_busy() )
                return notify_fail("����æ���أ��޷�����"+fabao_name+"��\n");

// ��ֹ�¹���������ɱ�� modifid by seng@2005-1-26
      if( attacker->query("name"))
                return notify_fail(HIR"��ɮ˵���¹�������������ɱ�ˣ�������"+fabao_name+"�����ͭ������\n"NOR);

        if( where->query("no_magic") || where->query("no_fight") )
                return notify_fail("���ﲻ�ܼ�"+fabao_name+"��\n");

        if( (int)attacker->query("mana") < 500 )
                return notify_fail("��ķ������ܿ���"+fabao_name+"��\n");
        if( (int)attacker->query("sen") < 200 )
                return notify_fail("���������ǲ��壬���Ѽ�Ԧ"+fabao_name+"��\n");

        if( !fabao->query("equipped") )
                return notify_fail(fabao_name+"��ûװ��������\n");

        message_vision(HIC"\n$N���㾫�񣬴��һ����������������ֻ��$n��������һ�·ɵ���գ�\n"NOR, attacker, fabao);
        message_vision(HIC"���Ǽ���ɫһ�䣬����������$n����һ����Х��$N��ջ�����\n\n"NOR,  target, fabao);

        //start kill...
        attacker->kill_ob(target);


        attacker->add("mana", -300);
        attacker->add("sen", -100);
        attacker->start_busy(3+random(3));


//1st, daoxing vs. daoxing, if target dx enough, can prevent anything from happening.

//2nd, combat_exp vs. daoxing, if target exp enough, can ����.

//3rd, fali vs. fali, if victim fali enough, can try use his/her defense fabao to ����.
//here, damage to fabao's power may happen...

//4th, to this point, a successful hit happens, consider damage now. 
//damage is determined by attacker and target's enchant and attacking fabao's power.

        a_dx = (int)attacker->query("daoxing");
        a_exp = (int)attacker->query("combat_exp"); //this parameter no use now.
        a_fali = (int)attacker->query("mana");
        a_enchant = (int)attacker->query("mana_factor");

        d_dx = (int)target->query("daoxing");
        d_exp = (int)target->query("combat_exp");
        d_fali = (int)target->query("mana");
        d_enchant = (int)target->query("mana_factor");

        //stage 1, attacker's dx vs. target's dx
        if( d_dx*100/(a_dx+d_dx) > random(100) )
        {
                //message_vision(HIW"\n���$N����һ���֣�����֮�飬Ҳ�Ź⻪��\n"NOR, attacker);   
                message_vision(HIW"\n���$N��һ���֣��ٺ�Ц�˼���������Ҷ�����ȥ�޸��������ɣ�\n"NOR, target);   
                message_vision(HIW"\nֻ��$n�����������ֻص���$N�����С�\n"NOR, attacker, fabao);    
                return 1;    
        }

        //stage 2, attacker's dx vs. target's exp
        //note here, 1/3 exp can be considered as effective dx.
        if( (d_exp/3)*100/(a_dx+d_exp/3) > random(100) )
        {
                message_vision(HIC"\n���$N���μ����������$n�Ĺ��ơ�\n"NOR, target, fabao);
                return 1;
        }
        
        //stage 3, attacker's fali vs. target's fali
        //if target has a higher fali, he/she may want to try ��ȡ�Է�������
        //btw, this is determined by his/her defense fabao's power, hoho.
        if( d_fali*100/(a_fali+d_fali) > random(100) )
        {
                d_fabao_power = 0;
                j = 0;
                a_fabao_power = fabao->query("fabao/max_attack_qi")+fabao->query("fabao/max_attack_shen");
                //note here, 2 defense fabaos->2 max_defense_shou parameters
                //compare with 1 attack fabao->max_attack_qi+max_attack_shen.

                //check if the victim equipped defense fabao...
	        inv = all_inventory(target);
                for( i=0; i<sizeof(inv); i++)
	        {
                        if( !inv[i]->query("series_no") 
                                ||  !inv[i]->query("fabao") 
                                || !inv[i]->query("equipped") 
                                || inv[i]->query("series_no") == "1" )
			        continue;//not a equipped defense fabao.

                        d_fabao_power += inv[i]->query("fabao/max_defense_shou");  
                        j = j+1;
                        if( j==1 ) d_fabao1 = inv[i];
                        else if ( j== 2 ) d_fabao2 = inv[i];                  
                }

                if( d_fabao_power > 0 )
                {
                        message_vision(HIC"$N�ߣ���һ��������֮�飬Ҳ�Ź⻪�����ҵķ�����\n"NOR, target);
                        if( d_fabao1 ) 
                                message_vision(HIW"ֻ��ϼ��һ����$N��$n�Ѹ�"+fabao_name+"����һ��\n"NOR, target, d_fabao1);
                        if( d_fabao2 ) 
                                message_vision(HIW"ֻ��ϼ��һ����$N��$n�Ѹ�"+fabao_name+"����һ��\n"NOR, target, d_fabao2);
                        
                        if( a_fabao_power > d_fabao_power )//possible to damage defense fabao...
                        {
                                if( random( a_fabao_power - d_fabao_power ) > 3 ) 
                                {
                                        if( d_fabao2 )
                                        {
                                                if( d_fabao2->query("fabao/max_defense_qi") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_qi", -1);
                                                if( d_fabao2->query("fabao/max_defense_shen") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_shen", -1);                                                
                                                if( d_fabao1->query("fabao/max_defense_shou") > 1 && random(2) == 0 )
                                                        d_fabao2->add("fabao/max_defense_shou", -1);

                                                message_vision(HIC"���Ѫ���ʢ��$N����һ����������������\n"NOR, d_fabao2);
                                                if( d_fabao2->unequip() ) d_fabao2->save(); 
                                        }
                                        else if( d_fabao1 )
                                        {
                                                if( d_fabao1->query("fabao/max_defense_qi") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_qi", -1);
                                                if( d_fabao1->query("fabao/max_defense_shen") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_shen", -1);                                                
                                                if( d_fabao1->query("fabao/max_defense_shou") > 1 && random(2) == 0 )
                                                        d_fabao1->add("fabao/max_defense_shou", -1);

                                                message_vision(HIC"���Ѫ���ʢ��$N����һ����������������\n"NOR, d_fabao1);
                                                if( d_fabao1->unequip() ) d_fabao1->save(); 
                                        }   
                                         
                                        return 1;
                                }
                        }
                        else if( d_fabao_power > a_fabao_power )//possible to damage attack fabao
                        {
                                if( random( d_fabao_power - a_fabao_power ) > 3 ) 
                                {
                                        if( fabao->query("fabao/max_attack_qi") > 1 )
                                                fabao->add("fabao/max_attack_qi", -1);
                                        if( fabao->query("fabao/max_attack_shen") > 1 )
                                                fabao->add("fabao/max_attack_shen", -1);        
                         
                                        message_vision(HIC"���Ѫ���ʢ��$n����һ����������Ȼ��$N���˹�ȥ��\n"NOR, target, fabao);  
                                        if( fabao->unequip() ) fabao->save();//here save may cause bug?...

                                        fabao->move(target); 
                                        return 1;
                                }
                        }
                
                        message_vision(HIC"���˫���ķ������˸�����൱��ֻ�ø����ջء�\n"NOR, fabao);   
                        return 1;     
                }
        }

        //stage 4, finally, the fabao results in a hit to the target...
        //compare target's enchant + defense fabao with attacker's attacking fabao + enchat
        hit_msg = HIC "���$n�����˸����ţ�\n" NOR;
        if( fabao->query_temp("fabao/attack_qi") > fabao->query_temp("fabao/attack_shen") )
        {//attack qi
                damage = fabao->query_temp("fabao/attack_qi")*attacker->query_spi() + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_qi", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "qi", hit_msg);
                        return 1;
                }
        }
        else if( fabao->query_temp("fabao/attack_qi") < fabao->query_temp("fabao/attack_shen") )
        {//attack shen
                damage = fabao->query_temp("fabao/attack_shen")*30 + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_shen", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "shen", hit_msg);
                        return 1;
                }
        }
        else
        {//both qi and shen
                damage = fabao->query_temp("fabao/attack_shen")*30 + a_enchant - (d_enchant/2+random(d_enchant/2));
                fabao->set_temp("fabao/attack_qi", 0);
                fabao->set_temp("fabao/attack_shen", 0);
                if( damage > 0 ) 
                {
                        SPELL_D->apply_damage(attacker, target, damage, "both", hit_msg);
                        return 1;
                }                
        }

        message_vision(HIC"���$NӲ��$nһ�ǣ�ȴ�Ǻ������ˣ�\n"NOR, target, fabao); 

        return 1;
}
