//Created by waiwai@2001/03/23
//´ºÖ®¸ÊÁØ(springC-rain)
// [1;31m´ËÎÄ¼ş½ûÖ¹¸ü¸ÄºÍÒÆ¶¯[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "´ºÖ®¸ÊÁØ" NOR, ({ "springC rain", "springC", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "µÎ");
		set("long", "ÕâÊÇÒ»µÎ¾§Ó¨µÄ´ºÖ®¸ÊÁØµÄÓêµÎ¡£\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropÊ±ÏûÊ§±êÖ¾
		set("material", "water");//Ë®ĞÔÎï¼ş±êÖ¾
    };
	// dropÊ±µÄÌØ¶¨Êä³öĞÅÏ¢
	set_temp("drop_msg", this_object()->query("name")+CYN" Ëæ·ç¶øÊÅ£¬ÏûÊ§ÔÚ¿ÕÆøÖĞ²»¼ûÁË¡«¡«¡«\n"NOR);

	setup();
}

