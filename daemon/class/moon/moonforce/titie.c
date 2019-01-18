// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

        if ( !target
        ||   !userp(target)
        ||    target->is_corpse()
        ||    target==me)
                return notify_fail("��Ҫ��˭�ⶾ��\n");
        if (!target->query_condition("xiangsi"))
                return notify_fail("����������Ҫ��İ�����\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");

        if( (int)me->query("force") - (int)me->query("max_force") <  600 )
                return notify_fail("�������������\n");

        if ((int)me->query_skill("moonforce",1)<80)
                return notify_fail("����ڹ���Ϊ���������˽����˼֮�ࡣ\n");
        
        message_vision(
                HIY "$N��������$nĬĬ�����뻳�У�$n����$N���˰����ů��˼��֮��ĬĬƽ����\n\n"NOR,
                me, target );
        if (random(me->query_skill("moonforce", 1)-60)>10)
        {
                target->apply_condition("xiangsi",0);
                message_vision(
                HIY "$N���������͵ĸ�����$n���мȸм����ְ�ο����������ĸ���������������˯�硣\n"NOR,
                me, target );
                target->set_temp("force_sleep",1);
                target->command_function("sleep");
                target->delete_temp("force_sleep");     
        }
        else 
        {
                message_vision(
                HIY "$NͻȻ��ɫ�԰ף��ƺ�����������������Ż��һ��Ѫ������\n"NOR,
                 me, target );
        }       
 
        target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
        me->add("force", -150);
        me->set("force_factor", 0);
        return 1;
}

