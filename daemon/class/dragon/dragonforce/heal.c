// heal.c

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

	message_vision("$N���ȶ�����ȫ�������������˿�Ҳ���������ˡ�\n", me);

        me->receive_curing("kee", 20 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}

