// tiejia.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("����", ({"iron armor","tiejia","jia","armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ�����������ס�\n");
                set("value", 3000);
                set("material", "steel");
                set("armor_prop/armor", 40);
		set("armor_prop/dodge", -10);
             }
			 setup();
}
