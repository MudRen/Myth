//Cracked by Roath
//xiangsi.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR""+me->name() + "�����鶾��ʹ��İ����ؿڣ�\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIR "�鶾�����ˡ�\n" NOR );
      message("vision", HIR""+me->name() + "�����鶾��ʹ��İ����ؿڣ�\n"NOR,
            environment(me), me);
   }
   me->receive_wound("kee", 100);
   me->receive_damage("kee", 100);
   me->apply_condition("xiangsi", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
