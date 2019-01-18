
// Rainy
// 07/09/98
// require:	mana 500
// can use 6 times.
// each time decrease to 75%


#include <skill.h>
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_UNIQUE;

//the following section is based on huangjin-baota, others are similar...
//------------------------------------------------------------------
//modified by weiqi, 07/31/98...refine settings, add functions
//fabao's spi is from 100 to 10000 in general,
//to match players with 100 years to 10000 years dx and 100 to 10000 fali.

//time needed: get 1 spi need input 50 mana, and wait 2 seconds, 
//so to get 10000 spi, need input 500*1000 mana, 
//and wait 20000 seconds~about 6 hours in the best case.

//damge: 100 + my_spi/5 - random(vic_mana/10) - vic_enchant*2;
//to a 2000 max_fali target(100 enchant), best case is 100+2000-200 = 1900
//worst case is 100+2000-400-600 = 1100
//to a 5000 max_fali target(250 enchant), best case  is 100+2000-500 = 1600
//worst case is 100+2000-1000-500 = 600
//to a 10000 max_fali target(enchant 500), best case is 100+2000-1000 = 1100
//worst case is 0.

//use once, power decrease to 50%
//------------------------------------------------------------------


#define MAX_SPI 6000 
//basically, this corresponding to 6000 fali and 6000 years of dx
//later on we will use it to determine hit or not
#define MIN_SPI 100

string show_status();

void create()
{
	set_name("��������", ({"biyu pipa", "hammer", "pipa", "fabao"}));
	set_weight(8000);
	if(clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long", "һ�ѱ���ɫ�����ã���ӡ���䣬�з����ң����ǡ��أ�ˮ���𣬷硱��\n");
		set("unit", "��");
		set("value", 100000);
		set("no_put",1);
		set("no_sell",1);
		set("unique", 1);
		set("replace_file", "/obj/money/gold");
		set("wield_msg", "$N�����������������У����Ღ�ң��ƺ��з��������\n");
		set("time_available", 6);
		set("spi", MIN_SPI);
	}
	init_hammer(30);
	set("is_monitored", 1);
	setup();
}

void init()
{
	check_owner();
	add_action("do_improve", "improve");
	add_action("do_addspi", "addspi"); //for wiz's convinience.
}

int do_addspi(string arg)
{
	object fabao = this_object();
	object me= this_player();

	if( !wizardp(me) ) return notify_fail("�㲻��ʹ�����ָ�\n");
	if( !this_object()->id(arg) ) return notify_fail("���������ĸ�������������\n");

	//add 1/10 MAX_SPI each time...
	if( (int)fabao->query("spi") >= MAX_SPI )
		return notify_fail("��������������Ѿ��������˼��ޣ�\n");

	fabao->add("spi", MAX_SPI/10);
	if( (int)query("spi") > MAX_SPI ) set("spi", MAX_SPI);  
	tell_object(me, show_status());
	return 1;
}

int do_improve(string arg)
{
	object me= this_player();
	object fabao= this_object();
	int cost = 100;//now fix cost as 100
	
	if( me->is_busy()
	|| me->is_fighting()
	|| me->query_temp("pending/exercising"))
		return notify_fail("����æ���أ�����\n");
        
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") )
		return notify_fail("���ﲻ�ܶ���������\n");

	if( !this_object()->id(arg) ) return notify_fail("�������ʲô������������\n");;

	if( (int)me->query("mana") < cost )
		return notify_fail("��ķ���̫�ͣ����ܶ���������\n");

	if( (int)fabao->query("spi") >= MAX_SPI )
		return notify_fail("��������������Ѿ��������˼��ޣ�\n");

	message_vision(HIC"$N˫�ֽ�����$n�����������дʣ����Լ��ķ���һ�������˹�ȥ��\n"NOR, me, fabao);
	
	me->add("mana", -cost);
	fabao->add("spi", cost/50); //so 100 mana can get 2 spi for the fabao
	if( (int)query("spi") > MAX_SPI ) set("spi", MAX_SPI);  
	me->start_busy(cost/50);
	call_out("improved", cost/50, me); //get 1 spi need wait 2 seconds.
	//note, here the speed is increased to double of the huangjin-baota.

	return 1;
}

int improved(object me)
{
	object fabao = this_object();
	message_vision(HIC"\n$N���е�$nͻȻ����һ����⣬���ַ��֮����\n"NOR, me, fabao);
	message_vision(HIC"$N��¶ϲɫ������һ����վ��������\n"NOR, me);
	tell_object(me, show_status());
	me->start_busy(1);
	return 1;
}	

string show_status()
{
	int i, percent;
	string status = this_object()->query("name") + "��";

	percent = 1 + query("spi")*25/MAX_SPI;
	if ( percent > 25 ) percent = 25;
	
	for(i=1; i<=25; i++) //
	{
		if( i <= percent ) status = status + "��";
		else status = status + "��";
	}

	status = status + "\n";

	return status;	 
}

int ji_ob(object victim)
{
	object fabao=this_object();
	object me=this_player();
	object where=environment(me);

	int my_spi;
	//from MIN_SPI to MAX_SPI(usually from 100 to 10000)

	int vic_enchant, vic_dx, vic_mana;

	int damage;

	if( me->is_busy() )
		return notify_fail("����æ���أ��޷������������á�\n");
	if( !victim )
		return notify_fail("��������˲������\n");
	if( where->query("no_magic") )
		return notify_fail("���ﲻ�ܼ��������á�\n");
	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в��ܼ��������á�\n");
	if( (int)me->query("mana") < 500 )
		return notify_fail("��ķ������ܿ��Ʊ������á�\n");
	if( (int)me->query("sen") < 200 )
		return notify_fail("���������ǲ��壬���Ѽ�Ԧ�������á�\n");


	message_vision(HIC"\n$N�����е����ã�������һ����Σ������԰տ������ģ��Ღ����������\n"NOR, me, fabao);
	message_vision(HIC"ֻ��$n��������һ�·ɵ���գ���������֮�������ڶ�������$N��ȥ��\n"NOR, victim, fabao);

	if( !victim->is_fighting(me) ) 
	{
		if( living(victim) ) 
		{
			if( userp(victim) ) 
				victim->fight_ob(me);
			else
				victim->kill_ob(me);
		}
		me->kill_ob(victim);
	}

	me->add("mana", -500);
	me->receive_damage("sen", 100);
	me->start_busy(1+random(3));

	my_spi = query("spi");
	fabao->add("time_available", -1);
	fabao->set("spi", my_spi*3/4);


//1st, compare dx, if victim dx enough, ����
//2nd, compare fali, if victim fali enough, can ����
//if no ���� and ����, a successful hit happens, consider damage now, 
//damage is determined by victim's enchant and current fali and fabao's spi
//...weiqi
	vic_mana = (int)victim->query("mana");
	vic_dx = (int)victim->query("daoxing");
	vic_enchant = (int)victim->query("mana_factor");

	if( random(vic_dx/1000) > my_spi ) // /1000 is to convert vic_dx to years
	{
		message_vision(HIC"\n$N������Ц���ƺ�˿������$nӰ�졣\n"NOR, victim, fabao);
	}
	else
	{//now ���� does not happen, try ����?
		if( random(vic_mana) > my_spi )
		{
			message_vision(HIC"\n$N���һ�����գ�����ֻ������֮����������$n������һ���ٸ�֮�����ڹԹԵطɵ���$N���С�\n"NOR, victim, fabao);
			fabao->move(victim);
		}
		else
		{//now a hit should happen, let's consider damage
			damage = 0;
			damage = 100 + my_spi/5 - random(vic_mana/10) - vic_enchant*2;
			//here, my_spi usually 100-10000, so damage maybe upto 2000
			//vic_mana maybe upto 2*vic's max_mana. 
			//note, vic_enchant has no random(), so it's more important...

			if( damage < 0 ) damage = 0;
			if( damage > 2000 ) damage = 2000; 

			if( damage > 0 )
			{
				message_vision(HIC"\n���$N������������ס���䷢��һ���ҽУ�\n"NOR,victim);
				victim->receive_damage("sen", damage);
				victim->receive_wound("sen", damage/2);
				COMBAT_D->report_sen_status(victim);
			}
			
		}
	}

	if( (int)fabao->query("time_available") < 1 ) 
	{
		message_vision("\nͻȻ��$N����һ����â������ȥ��\n", fabao);
		destruct(fabao);
	}

	return 1;
}

int ji (string target)
{
	object fabao = this_object ();
	object me = this_player();
	string name=fabao->query("name");
	object victim;

	if (!target)
		return notify_fail("�����˭��"+name+"��\n");

	victim=present(target,environment(me));
	return fabao->ji_ob(victim);
}

