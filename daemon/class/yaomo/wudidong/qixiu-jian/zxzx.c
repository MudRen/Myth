// zxzx.c
//write by yesi
//yeahsi@21cn.com

#include <ansi.h>
inherit SSERVER;

void check(object me);
void zxzx_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
        int skill;
        int sword_skill,qixiu_skill;
        
        skill = me->query_skill("huntian-qigong",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        qixiu_skill= me->query_skill("qixiu-jian",1);
                       
                               
        if( skill < 100 )  return notify_fail("��Ļ���������Ϊ������\n");
        if( sword_skill < 100 )  return notify_fail("��Ļ�������δ�����졣\n");
        if( qixiu_skill < 160 )  return notify_fail("������޽�δ�����졣\n");
/*        
        if( me->query_temp("zxzx") ) 
        {
                remove_effect(me);
                return 1;
        }
*/
        if( me->query_temp("zxzx") ) 
                return notify_fail("������ʹ�á�׷����Ѫ����\n");
          
        if (me->query_skill_mapped("force")!="huntian-qigong")
                return notify_fail("��׷����Ѫ��������ϻ�����������ʹ�á�\n");
        
        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("[׷����Ѫ]���ݿ�ɽ�޵׶�����֮�ܣ�\n");     
        
        if( time()-(int)me->query_temp("zxzx_end") < 10 )
                return notify_fail("����������������\n");       
               
        
        if( (int)me->query("force") < skill )     
                return notify_fail("�������������\n");
 
        me->add("force", -skill);
        message_vision(HIR "$N�ѻ�����������������һ�ܣ�ֻ������ɱ�����ڣ���˭����˳�ۡ�\n" NOR, me);
        me->set_temp("zxzx", 1);
        me->set_temp("zxzx_time",skill);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
        
                
        if (me->query_skill_mapped("force") != "huntian-qigong"
        || !objectp(weapon=me->query_temp("weapon")) 
        || (weapon->query("apply/skill_type") != "sword" 
        && weapon->query("skill_type") != "sword" ) 
        ||  me->query_skill_mapped("sword") != "qixiu-jian" )     
                remove_effect(me);
        else 
                if(me->query_temp("zxzx_time")<1)
                        remove_effect(me);                 
                else 
                {  
                        me->add_temp("zxzx_time",-1);
                        call_out("check", 1, me);
                }
                     
}


void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("zxzx");
        me->set_temp("zxzx_end",time());
        tell_object(me, GRN"�㽫���������ջص��\n"NOR);
}

void zxzx_effect(object me, object victim)
{   
        int damage,ini_damage_apply;
        string str;

        if ( random(2) )
        {
                ini_damage_apply = me->query_temp("apply/damage");
                me->add_temp("zxzx",1);
                message_vision(HIR"\n$Nһ���еУ�˫Ŀ������л���������$n�ֹ���һ�У�\n"NOR,me,victim);
                me->add_temp("apply/damage",15);
                damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
         
               
                if( damage > 0 )
                {
                        message_vision(HIR"\n$N���������˿��ϵ��ŵ�Ѫ��״����񣬾�Ȼ�ڲ����ܵ���������ٹ���һ�У�\n"NOR,me);
                        me->add_temp("apply/damage",15);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
                        me->add_temp("zxzx",-1);

                }             

                me->add_temp("zxzx",-1);
                me->set_temp("apply/damage",ini_damage_apply);
        }
}
 

