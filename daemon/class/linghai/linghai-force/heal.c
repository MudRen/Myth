//heal.c


#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�������ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
                return notify_fail("����ѪԲ��������Ҫ���ˡ�\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        message_vision(HIW"$N��ϥ������΢��˫Ŀ��˫��ʳָ��ԡ�"HIB"��һ�ᣬֻ��һ������֮����ָ��������\n"NOR, me);

        me->receive_curing("kee", 50 + (int)me->query_skill("force")/5 );
        me->receive_curing("sen", 50 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}


