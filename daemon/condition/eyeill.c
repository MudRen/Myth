//Cracked by Roath

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "�����׵�������һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "������׵�������һ����\n" NOR );
      message("vision", me->name() + "�����׵�������һ����\n",
            environment(me), me);
   }
   me->receive_wound("kee", 50);
   me->receive_damage("kee", 50);
   me->apply_condition("eyeill", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
