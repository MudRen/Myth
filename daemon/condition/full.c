//Last modified by waiwai@2001/04/19

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) me->delete_temp("shit");

	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

   if( !living(me) ) {
      message("vision", me->name() + "�����ͨ�죬�����÷���һ���ˡ�\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��������ͨ�죬�����÷���һ���ˡ�\n" NOR );
      message("vision", me->name() + "�����ͨ�죬�����÷���һ���ˡ�\n",
            environment(me), me);
   }
	me->set_temp("death_msg",HIY" û���ü����Է���������ˣ�����\n"NOR);
	me->set_temp("killbyname","û���ü�����");
	me->set_temp("killbyid","shit");
	me->set_temp("killbyB","����");

   me->add("kee", -20);
   me->add("sen", -20);
   me->apply_condition("full", duration - 1);


   return CND_CONTINUE;
}
