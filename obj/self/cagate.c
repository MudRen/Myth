//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIR "��觲�Ƭ" NOR, ({ "chipped agate" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "һƬ�������Ƭ������΢���ĺ�⡣\n" NOR);
                set("value", 20000);
		    set("unit", "Ƭ");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "fire");
                set("magic/power", 50);
	}
        setup();
}
