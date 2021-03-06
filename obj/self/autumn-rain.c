// Created by waiwai@2001/03/23
// 秋之瑟雨(autumn-rain)
// [1;31m此文件禁止更改和移动[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "秋之瑟雨" NOR, ({ "autumn rain", "autumn", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("long", "这是一滴晶莹的秋之瑟雨的雨滴。\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // drop时消失标志
		set("material", "water");//水性物件标志
    };
	// drop时的特定输出信息
	set_temp("drop_msg", this_object()->query("name")+CYN" 随风而逝，消失在空气中不见了～～～\n"NOR);

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
             return notify_fail("此地灵气不够，无法合并物品。\n");

	if( (int)me->query("force") < (int)me->query("max_force") )
		return notify_fail("你的内力不足，很难将物品合并。\n");

	if( (int)me->query("mana") < (int)me->query("max_mana") )
		return notify_fail("你的法力不足以支持合并物品。\n");
       }

       if ( !(b=present("summer rain",me)))
                return notify_fail(CYN"你将手中 "HIY"秋之瑟雨 "NOR CYN"摆弄了几下，却一点反应也没有。\n"NOR);

       if ( !(c=present("spring rain",me)))
                return notify_fail(CYN"你将手中 "HIY"秋之瑟雨 "NOR CYN"摆弄了几下，却一点反应也没有。\n"NOR);

       if ( !(d=present("winter rain",me)))
                return notify_fail(CYN"你将手中 "HIY"秋之瑟雨 "NOR CYN"摆弄了几下，却一点反应也没有。\n"NOR);

	if( item=new("/obj/self/item/4season")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("你的负重过高不能合并物品。\n");
		destruct(b);
		destruct(c);
		destruct(d);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N将手中的四滴雨滴融合在一起，只见几道耀眼霞光掠过,竟然合并出一缕四季精灵。\n"NOR,me);

	destruct(a);
	}
	return 1;
}

