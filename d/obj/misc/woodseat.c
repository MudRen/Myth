
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("Сľ��", ({ "seat","deng" }));
        set_weight(200);
	set("long", "һֻ�������гɵ�Сľ�ʡ�\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "wood");
		set("value", 20);
		set("no_get", 1);
		set("amount",30);
        }
        setup();
}

