//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIM "ˮ����Ƭ" NOR, ({ "chipped crystal" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "һƬ��ɫ��ˮ����Ƭ��\n" NOR);
                set("value", 20000);
		    set("unit", "Ƭ");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "magic");
                set("magic/power", 50);
	}
        setup();
}
