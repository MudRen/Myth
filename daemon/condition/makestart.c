// [1;31m´ËÎÄ¼ş½ûÖ¹ËæÒâ¸ü¸ÄÈÎºÎÉèÖÃ[0m
// Created by waiwai@2001/02/18
// »êÆÇ¾«Áé"¶¾"ÎÄ¼ş
// Ïà¹ØÎÄ¼ş£º
// elfnpc.c logind.c set.c damage.c 
// combatd.c quit.c score.c

#include <allobj.h>

#include <condition.h>

inherit F_CLEAN_UP;
#define ELF		WAI_NPC"elfnpc"

int update_condition(object me, int duration)
{
	int ratio;
	string elf, owner;
	object where, startroom, ob;
	int i;
	object *ob_list;
	ob_list = children(ELF);

	where = environment(me);
	startroom = me->query("Sroom");
	owner = ob_list->query("owner");

	if( sizeof(filter_array(owner,(:clonep:)))<1) {
	if( base_name(where) == me->query("Sroom") && me->query("hunpo")) {
	tell_object(me, "ÄãµÄ»êÆÇ¾«ÁéÏûÊ§ÁË¡£¡£¡£\n");
	me->clear_condition("makestart");
	}
	} //else return CND_CONTINUE;

	if( duration < 1 ){
		me->delete("hunpo");
	 	return 0;
	}

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");

    	if (ratio > 80) 
		tell_object(me, "Äã¾õµÃÍ·ÄÔ·¢ÔÎ£¬Éí×ÓÇáÆ®Æ®µÄ¡£\n");
    	else if (ratio > 60) 
		tell_object(me, "Äã¾õµÃÄÔ´üÓÖÍ´ÓÖÕÇ£¬Éí×ÓÒÑ²»´óÌıÊ¹»½ÁË¡£\n");
    	else if (ratio > 40) 
		tell_object(me, "Äã¾õµÃºôÎüÀ§ÄÑ£¬ÑÛÇ°Ò»ÇĞ¶¼Ä£ºıÁËÆğÀ´¡£\n");
    	else 
		tell_object(me, "Äã»è»èÓûË¯£¬ÂíÉÏ¾ÍÒªµ¹ÔÚµØÏÂÁË¡£\n");

	me->receive_wound("sen", 10);
	me->receive_wound("kee", 10);

	if (me->query("mana") < 0) me->set("mana", 0);
	me->set_temp("death_msg",HIW"»êÆÇ¾«ÁéÔ­ÉñÏûÉ¢¶øËÀ¡£¡£¡£\n"NOR);

	me->apply_condition("makestart", duration-10);  

	if( time()-me->set("nowstart")>1800 && me->query("hunpo")) {
	tell_object(me, "ÄãµÄ×¤Áô½ûÖ¹ÒÑ±»½â³ı¡£¡£¡£\n");
	me->delete("hunpo");
	me->clear_condition("makestart");
 	return 0;
	}

	if( !duration ) return 0;

	return CND_CONTINUE;
}

