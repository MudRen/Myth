// poison_sandu.c stey

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("sen", 35);
        me->receive_damage("sen", 35);
        me->receive_wound("kee", 35);
        me->receive_damage("kee", 35);
	me->apply_condition("poison_sandu", duration);
	tell_object(me, HIG "������ڶ����ڷ��������ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
