//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIG "ϡ�����" NOR, ({ "flawless jade" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIG "һ�����������ױȵĴ���䡣\n" NOR);
                set("value", 100000);
		    set("unit", "��");
//              set("can_be_enchased", 1);
		set("can_auction", 1);
                set("magic/type", "cold");
                set("magic/power", 125);
	}
        setup();
}
