// [1;31m´ËÎÄ¼ş½ûÖ¹ËæÒâ¸ü¸ÄÈÎºÎÉèÖÃ[0m
// Created by waiwai@2001/02/18
// ÃÅÅÉ×·É±"¶¾"ÎÄ¼ş

#include <ansi.h>

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int ratio;
	string mp;
	// Update By waiwai@2001/06/15 ÈÃÄ³Ğ©Npc²»ÅÂÓÃ¶¾
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

	mp = me->query("ZSmenpai");

	// ×·É±ÏŞÊ±Èı¸öĞ¡Ê±
	if( me->query("vendettaFT") && time() - me->query("vendettaFT") > 10800 ){
		message("channel:rumor",
		HIY"¡¾ÃÅÅÉ×·É±¡¿"HIR+log_id(me)+"±»ÃÅÅÉ"HIW"¡¸"+mp+"¡¹"HIR"×·É±Òò³¬Ê±¶ø±»·ÏÖ¹£¡\n"NOR,users());
		me->clear_condition("mpzs");
		me->remove_all_killer();
		me->delete("vendettaFT");
		me->delete("vendetta/"+mp);
		me->save();
	 	return 1;
	}

	if( !me->query("vendettaFT") || !userp(me) ) return 0;

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");

    	if (ratio > 0) 
		tell_object(me, "Äã¾õµÃĞÄÖĞ·¢Ğé£¬¸Ğ¾õµ½ËÆºõÕı±»ÃÅÅÉ"+mp+"×·É±¡£¡£¡£\n");

	me->receive_damage("kee", duration/10);
	me->receive_damage("sen", duration/10);

//	me->apply_condition("mpzs", duration - 1);

	me->set_temp("death_msg",HIW"±»ÃÅÅÉ"+mp+"×·É±»êÆÇÏÅÆÆ¶øËÀ¡£¡£¡£\n"NOR);

	if( !duration ) return 0;

	return CND_CONTINUE;
}

