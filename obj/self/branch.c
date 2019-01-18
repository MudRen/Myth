// Created by waiwai@2001/03/23
// ¿İÖ¦(Withered branch)
// [1;31m´ËÎÄ¼ş½ûÖ¹¸ü¸ÄºÍÒÆ¶¯[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "¿İÖ¦" NOR, ({ "withered branch", "branch", "withered" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¶Î");
		set("long", "ÕâÊÇÒ»¶Î±»·çÕÛ¶ÏµÄÊ÷Ö¦£¬ÉÏÃæ¹Ò×Å¼¸Æ¬Ò¶×Ó¡£\n");
		set("value", 100);
		set("can_auction", 1);
    };
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

       if ( !(b=present("magic agate",me)))
                return notify_fail(CYN"ÄãÉĞÈ± "HIR"ÉñÖ®Âêè§ "NOR CYN"ÎŞ·¨ºÏ³ÉÀ×ÁéÖé¡£\n"NOR);

       if ( !(c=present("4-season",me)))
                return notify_fail(CYN"ÄãÉĞÈ± "HIG"ËÄ¼¾"HIR"¾«Áé "NOR CYN"ÎŞ·¨ºÏ³ÉÀ×ÁéÖé¡£\n"NOR);

	if( item=new("/obj/self/item/leizhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("ÄãµÄ¸ºÖØ¹ı¸ß²»ÄÜºÏ²¢ÎïÆ·¡£\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N½«ÊÖÖĞµÄ "HIR"ÉñÖ®Âêè§ "HIG"ËÄ¼¾"HIR"¾«Áé"NOR WHT
	"Óë"NOR YEL"¿İÖ¦"NOR WHT"°ÚÔÚÒ»Æğ£¬Ö»¼û¼¸µÀÒ«ÑÛÏ¼¹âÂÓ¹ı,¾¹È»ºÏ²¢³öÒ»¿ÅÀ×ÁéÖé¡£\n"NOR,me);
        message("channel:rumor",
	WHT"©¯"HIR"Ğ¡µÀÏûÏ¢"NOR WHT"©¯ÌıËµ£º"+log_id(me)+"ºÏ³ÉÁË"HIB"À×ÁéÖé"NOR WHT"ÁË£¡\n"NOR,users() );

	destruct(a);
	}
	return 1;
}


