// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("sen", 10);
	me->receive_damage("kee", 10);
	me->set_temp("death_msg","��õ�嶾�������ˡ�\n");
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "���е�" HIR "��õ�嶾" HIG "�����ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
