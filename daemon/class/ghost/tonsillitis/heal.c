//Cracked by Roath
#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + "�������˹����ˣ���������һ�ź��������ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/10 );
        me->add("force", -50);

        return 1;
}

