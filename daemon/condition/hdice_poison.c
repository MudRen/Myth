//Created by waiwai@2001/10/20

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + HIY"���������ʹ��غ���һ����\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ���溮�ӵ�������������֫�ٺ������еĺ����Ʒ����ˣ�\n" NOR );
      message("vision", me->name() + HIR"������ͻȻ�������Σ����ظ�������������\n"NOR,
            environment(me), me);
   }
      me->receive_wound("kee",80 + random(10));
      me->receive_wound("sen", 80);
      me->set_temp("death_msg",HIW" ���к����ƶ��������ˡ�\n"NOR);
      me->apply_condition("hdice_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
	     me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
	     me->delete_temp("powerup");  }

	if( duration < 1 && (int)me->query("no_blade")>0  && !wizardp(me)
		&& (int)me->query("no_poison")>0 ) return 0;

   return CND_CONTINUE;
}
