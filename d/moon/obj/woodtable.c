
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ľ��", ({ "table","zhuo" }));
        set_weight(2000);
	set("long", "����һ��ľ���ӣ��䲻���£���Ҳʵ�á�\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
		set("value", 2000);
                set("no_get", 1);
		set("amount",30);
        }
        setup();
}

