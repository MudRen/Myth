// scorpion_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
         me->receive_wound("sen", 10);
         me->receive_damage("kee", 10);
         me->apply_condition("scorpion_poison", duration - 1);
         tell_object(me, HIG "��е��������ѣ���֫��������������\n" NOR );
         if( duration < 1 ) return 0;
         return 1;
}
