// lightarmor.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("�ټ�", ({"teng jia","tengjia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ������ټס�\n");
                set("value", 1500);
                set("material", "wood");
                set("armor_prop/armor", 25);
             }
			 setup();
}
