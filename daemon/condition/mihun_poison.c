// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("sen", 20);
        me->apply_condition("mihun_poison", duration - 1);
        tell_object(me, HIR "�������֫��ľ�������е�Ԫ����һ������ʧ��\n" NOR);
        if( duration < 1 ) return 0;
        return 1;
}

