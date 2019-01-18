// jldl.c
//write by yesi


#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string get_name(string str)
{
        str="��������";
        return str;
}

string get_help(string str)                
{
        str="ָ��: ��������������\n"
        +"����̫�����ڹ���������ǧ��ܹ����Է�������������ȥ��";
        return str;
}

void remove_effect(object me);
void check_mapped(object me);
string jldl_result(object me, object victim, int mod_val, int force_adj, mapping action);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("wuxiangforce",1);

        if( skill > 250 ) skill=250;
        
        if( target != me ) 
                return notify_fail("��ֻ���ý������������Լ��ķ�������\n");

        if(time()-(int)me->query_temp("jldl_end") < 10) return notify_fail("����������������\n");
        
        if( (int)me->query("force") < skill*2 )     
                return notify_fail("�������������\n");
                
        if (!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("[��������]�Ƿ���ɽ���Ƕ�����֮�ܣ�\n");                     
        
        if( me->query_temp("jldl") ) 
        {
                remove_effect(me);
                return 1;
        }

        me->add("force", -skill);
        message_vision(HIG "$N��С���๦����������һ�ܣ�ֻ�������������������޲����⣡\n" NOR, me);
        me->set_temp("jldl", 1);
        me->set_temp("jldl_time",skill);
        call_out("check_mapped", 1, me);
        
        return 1;
}


void check_mapped(object me)
{
        if(!me) return;                
        if( me->query_skill_mapped("force") != "wuxiangforce" ) 
        remove_effect(me);
        else 
                if(me->query_temp("jldl_time")<1)
                remove_effect(me);                      
                else 
                {  
                        me->add_temp("jldl_time",-1);
                        call_out("check_mapped", 1, me);
                }
}


void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check_mapped");
        me->delete_temp("jldl");
        me->set_temp("jldl_end", time() );
        tell_object(me, "��Ľ�����������һ������ϣ��������ջص��\n");
}


string jldl_result(object me, object victim, int mod_val, int force_adj,mapping action)
{   
        string result,str;
        int me_force,v_dodge;
        object vweapon;
        int damage, damage_bonus,defense_factor,wounded;
        mixed foo;   
 
        if( force_adj > mod_val*3/4 )        
                return HIG"$n����һ����$N��ʽ���Ա���΢����һ�¡�\n"NOR;                    
        else
        {
                if (!vweapon=victim->query_temp("weapon")) 
                        result = HIG"$n����һ����$N��ʱ����������ת��ȭͷ�����Լ�������ֱײ��ȥ��\n"NOR;
                else 
                        result =HIG"$n����һ����$N��ʱ����������ת��"+vweapon->name()+HIG"�����Լ�������ֱײ��ȥ��\n"NOR;
                
                me_force = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK); if( me_force < 1) me_force = 1;
                v_dodge  = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE); if( v_dodge < 1) v_dodge = 1;
                
                       
                if ( random(me_force) < random(v_dodge) )
                {
                        result += random(2) ? "$Nһ����¿�������ͷ�����Ķ㿪�ˡ�\n" : "��$N����׼�������$n���߶�ûմ�ϡ�\n";
                        return result;
                }
                     
                else  
                { 
                        damage = victim->query_temp("apply/damage");
                        wounded = 0;
                        if( action["damage"] )  damage += action["damage"] * damage / 100;
                        damage_bonus = victim->query_str();
                        if( me->query("force_factor") && (me->query("force") > me->query("force_factor")) )   
                        {
                                damage_bonus += me->query("force_factor");
                                me->add("force",-victim->query("force_factor"));
                        }
                        if( victim->query("force_factor") && (victim->query("force") > victim->query("force_factor")) )   
                        {
                                damage_bonus += victim->query("force_factor");
                                victim->add("force",-victim->query("force_factor"));
                        }
                        damage += (damage_bonus + random(damage_bonus))/2;
                        defense_factor = victim->query("combat_exp");
                        while( random(defense_factor) > me->query("combat_exp") ) 
                        {
                                damage -= damage / 3;
                        }
                        damage = victim->receive_damage("kee", damage, me );
                        if( (me->is_killing(victim) || vweapon) && random(damage) > (int)victim->query_temp("apply/armor") ) 
                        {
                                victim->receive_wound("kee",damage - (int)victim->query_temp("apply/armor"), me, "exert");
                                wounded=1;
                        }
                        str = COMBAT_D->damage_msg(damage, action["damage_type"]);
                        str = replace_string( str, "$n", "$N" );
                        str = replace_string( str, "$p", "$N" );
                        result += str;
                        if ( damage > 0 && wounded)  result += "( $N" + COMBAT_D->eff_status_msg(
                               (int)victim->query("eff_kee") * 100 /(1+(int)victim->query("max_kee")) ) 
                               + " )\n";
                        else result +=   "( $N" + COMBAT_D->status_msg(
                               (int)victim->query("kee") * 100/(1+(int)victim->query("max_kee")) ) 
                               + " )\n";              
                        return result;
                }
        }
}

