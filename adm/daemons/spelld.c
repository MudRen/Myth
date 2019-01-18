// spell_d.c.
// mon 12/6/98

#include <ansi.h>

/* table for ������� 
   for example,
        "dao": ({"yaofa","dengxian-dafa"}),
   means, dao can ���� yaofa and dengxian-dafa.
   */
mapping table=([
        // xian
        "baguazhou": ({"dengxian-dafa"}),
        "buddhism": ({"pingtian-dafa"}),
        "dao": ({"yaofa","tianmo"}),
        "taiyi": ({"moonshentong"}),
        "taoism": ({"dengxian-dafa"}),
        // yao
        "dengxian-dafa": ({"moonshentong"}),
        "pingtian-dafa": ({"seashentong","taoism"}),
        "tianmo": ({"buddhism"}),
        "yaofa": ({"gouhunshu"}),
        // neutral
        "gouhunshu": ({"baguazhou"}),
        "moonshentong": ({"tianmo","dao"}),
        "seashentong": ({"taiyi","taoism"}),
        ]);

/* determine whether two ���� are �����
   if spell1 ���� spell2, then return = 1.
   if spell2 ���� spell1, then return = -1.
   otherwise, return 0.
   */
int skill_xiangke(string spell1, string spell2)
{
    int neutral=0;
    int result;
    
    if(undefinedp(table[spell1]) ||
            undefinedp(table[spell2])) return neutral;

    if(member_array(spell1, table[spell2])>-1) {
        // spell2 can ���� spell1.
        result=-1;
    } else if(member_array(spell2, table[spell1])>-1) {
        // spell1 can ���� spell2.
        result=1;
    } else {
        result=neutral;
    }
    
    return result;
}

/* determine whether two players' ���� are �����
   only effective between two players,
   or a NPC against a player,
   can't a player take advantage of a npc.
   if obj1 ���� obj2, then return = 1.
   if obj2 ���� obj1, then return = -1.
   otherwise, return 0.
   */
int check_xiangke(object obj1, object obj2)
{
    int neutral=0;
    int result;
    string skill1, skill2;
    
    skill1=obj1->query_skill_mapped("spells");
    skill2=obj2->query_skill_mapped("spells");

    // need at least 20 level of special spells.
    if((int)obj1->query_skill(skill1,1)<20) return neutral;
    if((int)obj2->query_skill(skill2,1)<20) return neutral;

    result=skill_xiangke(skill1, skill2);
    
    if(!userp(obj1)) { // obj1 is npc
        if(userp(obj2) && result== -1)
            result=0;
    } else if(!userp(obj2)) { // obj2 is npc, obj1 is player
        if(result==1)
            result=0;
    }

    return result;
}

int attacking_cast_success(object attacker, object target, int success_adj)
{
        int ap, dp, success;
        int xk;
 
        if (!objectp(target)) return 0;
        ap = attacker->query_skill("spells");
        ap = ( ap * ap * ap / 10 ); //this is from skill.
        //at high daoxing, the skill level can not follow, so need adjustment here.
        ap = ap*(1+attacker->query("daoxing")/500000);
        ap = ap+attacker->query("daoxing");
        dp = target->query("daoxing") + target->query("combat_exp")/3;
        //note here, combat_exp is also useful in avoiding been casted.

        success = 0;

        if ( success_adj < 20 ) success_adj = 20;
        else if( success_adj > 500 ) success_adj = 500;

        ap = ap*success_adj/100;

        // mon 01/22/99
        xk=check_xiangke(attacker, target);
        if(xk==1) {
            dp=dp/5;
        } else if(xk==-1) {
            ap=ap/5;
        }

        if( random(100)>dp*100/(ap+dp) ) success = 1;

        return success; 
}

int attacking_cast_damage(object attacker, object target, int damage_adj)
{
        int a_fali, d_fali, damage;
        int xk;

        if( damage_adj < 50 ) damage_adj = 50;
        else if( damage_adj > 200 ) damage_adj = 200;

        //will use current fali...but do not allow it exceeds 2 time of the max.
        a_fali = attacker->query("mana");
        if( a_fali > 2*attacker->query("max_mana") ) a_fali = 2*attacker->query("max_mana");
        d_fali = target->query("mana");
        if( d_fali > 2*target->query("max_mana") ) d_fali = 2*target->query("max_mana");


        //fali and shen.
        a_fali=a_fali/20+random(attacker->query("eff_sen") / 20);
        d_fali=d_fali/20+random(target->query("eff_sen") / 20);

        //mana_factor, here the attacker has some advantage.
        //the damage_adj higher, the better for attacker.
        a_fali+=(2*damage_adj/100)*(attacker->query("mana_factor"));
        d_fali+=(2*damage_adj/100)*random(target->query("mana_factor"));

        xk=check_xiangke(attacker, target);
        if(xk==1) {
            d_fali/=5;
        } else if(xk==-1) {
            a_fali/=5;
        }

        damage=(a_fali-d_fali)/2;

        //for backfire, we need let it be serious...
        if( damage < 0 ) damage = damage - target->query("mana_factor"); 
        //here increase the damage, since previously it's included in random()

        damage = damage*damage_adj/100; //last damage scaled again.

        //finally, we need let the spell level useful...
        //the setting is, at enabled level 200, the damage will double.
        if( damage > 0 )
        {
            damage += (damage*(int)attacker->query_skill("spells"))/300;
        }
        else if ( damage < 0 )
        {
            damage += (damage*(int)target->query_skill("spells"))/300;
        }
        
        return damage;
}

//weiqi 981206
//this function can be called when want apply a damage to a victim while allow
//the victim use his/her self-made fabao to defense.
void apply_damage(object winner, object victim, 
        int damage, string damage_type, string msg_hit)
{
        int i, temp, type, damage_qi, damage_shen,adjust,success;
        object *inv;
        int def_count = 0;
        string *msg_fabao = ({
                "ֻ��$N��$nϼ��һ����\n",
                "ֻ��$N��$nϼ��������\n",
                "ֻ��$N��$nϼ����һ����\n",
                "ֻ��$N��$nϼ����һ����\n"
        });

        if( victim->query_temp("anti_magic") )
        {
                adjust=(int)victim->query_temp("anti_magic");

                if( (int)victim->query("mana") < adjust)
                        success=0;
                else
                        success=1;

                if( success )
                {
                        victim->add("mana", -adjust);
                        damage_qi=damage_qi - adjust/2;
                        damage_shen=damage_shen - adjust/2;
                        if ( damage_qi > 0 || damage_shen > 0 )
                                message_vision("\nֻ��$N���ó�ǧ���������ס��$n�Ĺ��ơ�\n", victim, winner);
                        else
                                message_vision("\nֻ��$N���ó�ǧ���������$n�Ĺ��ƾ������⡣\n", victim, winner);
                }
        }


        if( damage <= 0 ) return;

        if(damage_type == "qi" || damage_type == "kee") 
        {
                damage_qi = damage;
                damage_shen = 0;
                type = 0;
        }
        else if(damage_type == "shen" || damage_type == "sen") 
        {
                damage_qi = 0;
                damage_shen = damage;
                type = 1;
        }
        else 
        {
                damage_qi = damage;
                damage_shen = damage;
                type = 2;
        }

        //check if the victim equipped defense fabao...
        inv = all_inventory(victim);
        for( i=0; i<sizeof(inv); i++)
        {
                if( !inv[i]->query("series_no") ||  !inv[i]->query("fabao") || !inv[i]->query("equipped") )
                        continue;//not a equipped fabao.

                if( (type == 0) || (type == 2) ) //check if can reduce damage_qi.
                {
                        temp = inv[i]->protect_qi(damage_qi);
                        //temp is the damage left after fabao takes effect.

                        if( temp < damage_qi ) //means fabao useful.
                        {
                                damage_qi = temp;
                                message_vision(msg_fabao[def_count], victim, inv[i]);
                                def_count++;    
                        }
                }

                if( (type == 1) || (type == 2) ) //check if can reduce damage_shen.
                {
                        temp = inv[i]->protect_shen(damage_shen);
                        //temp is the damage left after fabao takes effect.

                        if( temp < damage_shen ) //means fabao useful.
                        {
                                damage_shen = temp;
                                message_vision(msg_fabao[def_count], victim, inv[i]);
                                def_count++;    
                        }
                }
        }//end of for i=0 loop.

        //finally we can make damage to the victim...
        if( damage_qi > 0 || damage_shen > 0 )
                //produce the hit message...
                message_vision(msg_hit, winner, victim);
        else
                //the fabao saved the target...
                message_vision("���$N�Ĺ�����ȫ��$n�ķ�����ס��
\n", winner, victim);

        if( damage_qi > 0 )
        {
                victim->receive_damage("kee", damage_qi, winner, "cast");
                victim->receive_wound("kee", damage_qi/2, winner);      
                COMBAT_D->report_status(victim);        
PFM_D->test_msg(winner, victim,
"receiver_damage_kee��" + damage_qi + "��receiver_wound_kee��" + damage_qi / 2);
        }
        if( damage_shen > 0 )
        {
                victim->receive_damage("sen", damage_shen, winner, "cast");
                victim->receive_wound("sen", damage_shen/2, winner);    
                COMBAT_D->report_sen_status(victim);
PFM_D->test_msg(winner, victim,
"receiver_damage_sen��" + damage_shen + "��receiver_wound_sen��" + damage_shen / 2);
        }

        return;
}

/*
weiqi 981206
attacking-cast...called from spells function.
a typical call would be:

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$N����ָͷѸ������ͻȻ����һ�磡��Ȼ��������������һ����$n��ȥ��\n" NOR,
                        //initial message
                HIC "���$n���յý�ͷ�ö\n" NOR, 
                        //success message
                HIC "����$n����һ���Ͷ��˿�����\n" NOR, 
                        //fail message
                HIC "���ǻ��汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR, 
                        //backfire initial message
                HIC "���̫������ɣ�$n���յý�ͷ�ö\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );
*/
void attacking_cast(
        object attacker, 
        object target, 
        int success_adj, 
        int damage_adj, //default value is 100 for this 2 parameters.
        string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
        string msg_init, 
        string msg_success, 
        string msg_fail, 
        string msg_backfire_init,
        string msg_backfire_success)
{
        int damage;

        //first, show the initial message...
        message_vision( msg_init, attacker, target );
        
        //calculate if the casting can happen...
        if( attacking_cast_success(attacker, target, success_adj) == 0 )
        {
                message_vision( msg_fail, attacker, target );
                //let the target kill attacker.
                if (target) attacker->kill_ob(target);      
                return;
        }
        
        damage = attacking_cast_damage(attacker, target, damage_adj);

        if( damage > 0 ) //attacker hit target
        {
                apply_damage(attacker, target, damage, damage_type, msg_success);
        }
        else if( damage < 0 ) //backfire
        {
                message_vision(msg_backfire_init, attacker, target);
                apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
        }

        else //damge=0
                message_vision(HIB "������ñ�$N�Է�����ס��˭Ҳû�гԿ���\n" NOR, target);

        //let the target kill attacker.
        attacker->kill_ob(target);

        return;
}


