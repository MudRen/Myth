// Created by waiwai@2001/03/23
// ÇïÖ®ÉªÓê(autumn-rain)
// [1;31m´ËÎÄ¼ş½ûÖ¹¸ü¸ÄºÍÒÆ¶¯[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "ÇïÖ®ÉªÓê" NOR, ({ "autumn rain", "autumn", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "µÎ");
		set("long", "ÕâÊÇÒ»µÎ¾§Ó¨µÄÇïÖ®ÉªÓêµÄÓêµÎ¡£\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropÊ±ÏûÊ§±êÖ¾
		set("material", "water");//Ë®ĞÔÎï¼ş±êÖ¾
    };
	// dropÊ±µÄÌØ¶¨Êä³öĞÅÏ¢
	set_temp("drop_msg", this_object()->query("name")+CYN" Ëæ·ç¶øÊÅ£¬ÏûÊ§ÔÚ¿ÕÆøÖĞ²»¼ûÁË¡«¡«¡«\n"NOR);

	setup();
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, d, item;

	me=this_player();
	a=this_object();

	if( !wizardp(me) && userp(me) ) {
       if(!environment(me)->query("cold"))
             return notify_fail("´ËµØÁéÆø²»¹»£¬ÎŞ·¨ºÏ²¢ÎïÆ·¡£\n");

	if( (int)me->query("force") < (int)me->query("max_force") )
		return notify_fail("ÄãµÄÄÚÁ¦²»×ã£¬ºÜÄÑ½«ÎïÆ·ºÏ²¢¡£\n");

	if( (int)me->query("mana") < (int)me->query("max_mana") )
		return notify_fail("ÄãµÄ·¨Á¦²»×ãÒÔÖ§³ÖºÏ²¢ÎïÆ·¡£\n");
       }

       if ( !(b=present("summer rain",me)))
                return notify_fail(CYN"Äã½«ÊÖÖĞ "HIY"ÇïÖ®ÉªÓê "NOR CYN"°ÚÅªÁË¼¸ÏÂ£¬È´Ò»µã·´Ó¦Ò²Ã»ÓĞ¡£\n"NOR);

       if ( !(c=present("spring rain",me)))
                return notify_fail(CYN"Äã½«ÊÖÖĞ "HIY"ÇïÖ®ÉªÓê "NOR CYN"°ÚÅªÁË¼¸ÏÂ£¬È´Ò»µã·´Ó¦Ò²Ã»ÓĞ¡£\n"NOR);

       if ( !(d=present("winter rain",me)))
                return notify_fail(CYN"Äã½«ÊÖÖĞ "HIY"ÇïÖ®ÉªÓê "NOR CYN"°ÚÅªÁË¼¸ÏÂ£¬È´Ò»µã·´Ó¦Ò²Ã»ÓĞ¡£\n"NOR);

	if( item=new("/obj/self/item/4season")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("ÄãµÄ¸ºÖØ¹ı¸ß²»ÄÜºÏ²¢ÎïÆ·¡£\n");
		destruct(b);
		destruct(c);
		destruct(d);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N½«ÊÖÖĞµÄËÄµÎÓêµÎÈÚºÏÔÚÒ»Æğ£¬Ö»¼û¼¸µÀÒ«ÑÛÏ¼¹âÂÓ¹ı,¾¹È»ºÏ²¢³öÒ»ÂÆËÄ¼¾¾«Áé¡£\n"NOR,me);

	destruct(a);
	}
	return 1;
}

