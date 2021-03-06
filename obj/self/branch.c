// Created by waiwai@2001/03/23
// 枯枝(Withered branch)
// [1;31m此文件禁止更改和移动[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "枯枝" NOR, ({ "withered branch", "branch", "withered" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "段");
		set("long", "这是一段被风折断的树枝，上面挂着几片叶子。\n");
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
             return notify_fail("此地灵气不够，无法合并物品。\n");

	if( (int)me->query("force") < (int)me->query("max_force") )
		return notify_fail("你的内力不足，很难将物品合并。\n");

	if( (int)me->query("mana") < (int)me->query("max_mana") )
		return notify_fail("你的法力不足以支持合并物品。\n");
       }

       if ( !(b=present("magic agate",me)))
                return notify_fail(CYN"你尚缺 "HIR"神之玛瑙 "NOR CYN"无法合成雷灵珠。\n"NOR);

       if ( !(c=present("4-season",me)))
                return notify_fail(CYN"你尚缺 "HIG"四季"HIR"精灵 "NOR CYN"无法合成雷灵珠。\n"NOR);

	if( item=new("/obj/self/item/leizhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("你的负重过高不能合并物品。\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N将手中的 "HIR"神之玛瑙 "HIG"四季"HIR"精灵"NOR WHT
	"与"NOR YEL"枯枝"NOR WHT"摆在一起，只见几道耀眼霞光掠过,竟然合并出一颗雷灵珠。\n"NOR,me);
        message("channel:rumor",
	WHT"┋"HIR"小道消息"NOR WHT"┋听说："+log_id(me)+"合成了"HIB"雷灵珠"NOR WHT"了！\n"NOR,users() );

	destruct(a);
	}
	return 1;
}


