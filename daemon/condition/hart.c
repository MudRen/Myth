// Update by waiwai@2001/02/18

#include <ansi.h>

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 ÈÃÄ³Ğ©Npc²»ÅÂÓÃ¶¾
	if( duration < 1 || me->query("no_poison")>0 || wizardp(me) ) return 0;

	if( duration >= 1 ) {
        tell_object( me , HIY "ÄãÖĞÁË¾«ÁéÖ®Îè,Ö»¾õµÃÈ«Éí¾­ÂöºÃÏñÒÆÎ»°ã,Ê®·ÖÍ´¿à£¡£¡£¡\n" NOR);

	message("vision", 
	me->name(1) + "[1;37mÉíÉÏµÄ¾«ÁéÖ®Îè°µÉË·¢×÷,Õû¸öÈËÇüÔÚµØÉÏ±íÏÖ³ö¼«ÎªÍ´¿àµÄ±íÇé£¡£¡£¡[0m \n",
	environment(me), me);

	if(me->is_fighting()) me->start_busy(1);

        me->add("kee",-150);
        me->add("sen",-150);
        me->add("force",-150);

       if( me->query("force") < 0 ) me->set("force",0);
	me->set_temp("death_msg",HIG"¾«ÁéÖ®Îè¶¾ÉË·¢×÷¶øËÀ¡£¡£¡£\n"NOR);
//	me->set("killbyname","¾«ÁéÖ®Îè¶¾ÉË·¢×÷¶øËÀ\n"NOR);

        me->apply_condition("hart",duration -1);
        COMBAT_D->report_status(me, 1);
	}
	return 1;
}
