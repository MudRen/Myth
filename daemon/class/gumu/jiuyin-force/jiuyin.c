//moonforce--heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
                return
notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIY "��������Ĭ�˾����澭��һ�������������֫�ٺ��������ߡ�\n" NOR);
        message("vision",
                YEL + me->name() +
"���������һ˿�����Ӱٻ�Ѩ���Ƹ��ϣ�������ȫ��......\n"
NOR,
                environment(me), me);
        me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}

