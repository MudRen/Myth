//Created by waiwai@2001/10/20

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 让某些Npc不怕用毒
	if( duration < 1 || me->query("no_poison")>0 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + HIY"浑身颤抖，痛苦地哼了一声。\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然一阵奇寒从丹田升起，沁入四肢百骸，你中的寒毒掌发作了！\n" NOR );
      message("vision", me->name() + HIR"的身子突然晃了两晃，牙关格格地响了起来。\n"NOR,
            environment(me), me);
   }
      me->receive_wound("kee",80 + random(10));
      me->receive_wound("sen", 80);
      me->set_temp("death_msg",HIW" 身中寒毒掌毒发身亡了。\n"NOR);
      me->apply_condition("hdice_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
	     me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
	     me->delete_temp("powerup");  }

	if( duration < 1 && (int)me->query("no_blade")>0  && !wizardp(me)
		&& (int)me->query("no_poison")>0 ) return 0;

   return CND_CONTINUE;
}
