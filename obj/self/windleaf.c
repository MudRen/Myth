// Created by waiwai@2001/03/23
// ÂäÒ¶(Fallen leaves)
// [1;31m´ËÎÄ¼ş½ûÖ¹¸ü¸ÄºÍÒÆ¶¯[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "ÂäÒ¶" NOR, ({ "fallen leaves", "leaves", "fallen" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Æ¬");
		set("long", "ÕâÊÇÒ»Æ¬±»·ç´µÂäµÄÂäÒ¶£¬Í¸×Å÷öÈ»µÄÓÇÉË¡£\n");
		set("value", 100);
		set("des", 1);
		set("can_auction", 1);
    };
	set_temp("drop_msg", "Æ®Âä²»¼ûÁË£¡\n");//dropÊ±µÄÊä³öĞÅÏ¢

	setup();
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, item;

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

       if ( !(b=present("magic jade",me)))
                return notify_fail(CYN"ÄãÉĞÈ± "HIG"ÉñÖ®ôä´ä "NOR CYN"ÎŞ·¨ºÏ³É»ğÁéÖé¡£\n"NOR);

       if ( !(c=present("lan crystal",me)))
                return notify_fail(CYN"ÄãÉĞÈ± "HIM"À¶¾§ "NOR CYN"ÎŞ·¨ºÏ³É»ğÁéÖé¡£\n"NOR);

	if( item=new("/obj/self/item/huozhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("ÄãµÄ¸ºÖØ¹ı¸ß²»ÄÜºÏ²¢ÎïÆ·¡£\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N½«ÊÖÖĞµÄ "HIG"ÉñÖ®ôä´ä "HIM"À¶¾§"NOR WHT
	"Óë"NOR YEL"ÂäÒ¶"NOR WHT"°ÚÔÚÒ»Æğ£¬Ö»¼û¼¸µÀÒ«ÑÛÏ¼¹âÂÓ¹ı,¾¹È»ºÏ²¢³öÒ»¿Å»ğÁéÖé¡£\n"NOR,me);
        message("channel:rumor",
	WHT"©¯"HIR"Ğ¡µÀÏûÏ¢"NOR WHT"©¯ÌıËµ£º"+log_id(me)+"ºÏ³ÉÁË"HIR"»ğÁéÖé"NOR WHT"ÁË£¡\n"NOR,users() );

	destruct(a);
	}
	return 1;
}

