#include <ansi.h>
inherit SSERVER;
void end(object,int);
int perform(object me, object target)
{       
        object weapon, ob;        int damage;
        string msg;
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");       
               if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("��ֻ�ܶ�ͬ�ط��Ķ���ʹ�á�\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�𵶹���ֻ�ܶ�ս����ʹ�á�\n");
        if(me->query("family/family_name")!="�䵱ɽ������")
                return notify_fail("��������Ӳ����á��𵶡���\n");
        if( (int)me->query_skill("chunqiu-blade", 1) < 80 )
                return notify_fail("��Ĵ��ﵶ��������죬����ʹ�á��𵶡���\n");
        if( (int)me->query_skill("dangmo-xinjing", 1) < 80 )
                return notify_fail("��ĵ�ħ�ľ������ߣ�����������ʹ���𵶡�\n");
        if( (int)me->query("force", 1) < 500 )
                return notify_fail("����������̫��������ʹ���𵶡�\n");
        if( target->query_temp("blade")==1)
                return notify_fail(target->query("name")+"������Ĺ������ţ��칦������ \n");
        msg = CYN "$NͻȻ���˷��ƵĿ���Ϳ�����$n��\n"NOR;
        me->add("force", -100);
        me->start_busy(1);              
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
                msg += CYN"$p���ŵû�������ʹ����ȫ����\n"NOR;
                target->start_busy(2);
                me->add("force",-100);          
                damage=me->query_skill("chunqiu-blade",1);
                damage=0-damage/8-random(damage/8);
                if(!target->query_temp("apply/attack"))
                    target->set_temp("apply/attack",damage);
                else 
                    target->add_temp("apply/attack",damage);
                if(!target->query_temp("apply/defense"))
                    target->set_temp("apply/defense",damage);
                else 
                    target->add_temp("apply/defense",damage);
                target->set_temp("sword",1);
                call_out("end",30,target,damage);
        }                                                 
        else
        { 
                msg += HIR"$p����Ӧս��һ�㶼����Ӱ�죡\n"NOR;              
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  target->delete_temp("blade");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N���ڴ��𵶵���Ӱ��ָ��˳�����\n"NOR,target);
}

