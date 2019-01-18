// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

        if ( !target
        ||   !userp(target)
        ||    target->is_corpse()
        ||    target==me)
                return notify_fail("������˭���ʴ���䣿\n");
        if (!target->query_condition("moon_poison"))
                return notify_fail("û��ʴ����Ϲ����ʲô��\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");

        if( (int)me->query("force") - (int)me->query("max_force") <  600 )
                return notify_fail("�������������\n");

        if ((int)me->query_skill("moonforce",1)<80)
                return notify_fail("����ڹ���Ϊ���������˽��ʴ���䡣\n");
        
        message_vision(
                HIY "$N��������ĬĬ����������$n��$N������࣬Խ��Խ�ǳ�Ͱ�����ȫ����������ʥ��Ĺ�ԡ�\n\n"NOR,
                me, target );
        if (random(me->query_skill("moonforce", 1)-60)>10)
        {
                target->apply_condition("moon_poison",0);
                message_vision(
                HIY "$N�о�������Խ��Խ��ͣ�$n���мȸм����ְ�ο�����������ϵ����������˯�硣\n"NOR,
                me, target );
                target->set_temp("force_sleep",1);
                target->command_function("sleep");
                target->delete_temp("force_sleep");     
        }
        else 
        {
                message_vision(
                HIY "$NͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ������\n"NOR,
                 me, target );
        }       
 
        target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
        me->add("force", -150);
        me->set("force_factor", 0);
        return 1;
}

