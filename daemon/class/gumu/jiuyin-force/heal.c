//moonforce--heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return
notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIW "�㻺�����£�����������ٸ�ȫ���泩�ޱ�\n" NOR);
        message("vision",
                WHT + me->name() +
"�������£�ȫ��ɢ�����⣬һ˿�����Ӱٻ�Ѩ���Ƹ��ϣ�ϸ�����ϣ��������......\n"
NOR,
                environment(me), me);
        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}

