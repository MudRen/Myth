// Created by aeddy@2001/03/23
// ¾§Ó¨Ëª»ª(autumn-frost)
// [1;31m´ËÎÄ¼ş½ûÖ¹¸ü¸ÄºÍÒÆ¶¯[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "¾§Ó¨Ëª»ª" NOR, ({ "autumn frost", "frost" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Á£");
		set("long", "ÕâÊÇÒ»Á£¾§Ó¨µÄ¾§Ó¨Ëª»ª£¬Ö»ÓĞÔÚÉîÇïÇçÀÊµÄÁè³¿²Å¼ûµÃµ½µÄ¾«Áé¡£\n");
		set("value", 100);
		set("can_auction", 1); // ¿ÉºÏ²¢±êÖ¾
		set("des", 1); // dropÊ±ÏûÊ§±êÖ¾
		set("material", "ice");//±ùË®ĞÔÎï¼ş±êÖ¾
    };
	// dropÊ±µÄÌØ¶¨Êä³öĞÅÏ¢
	set_temp("drop_msg", this_object()->query("name")+CYN" Ëæ·ç¶øÊÅ£¬ÏûÊ§ÔÚ¿ÕÆøÖĞ²»¼ûÁË¡«¡«¡«\n"NOR);

	setup();
}

