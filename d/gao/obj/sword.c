// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����", ({"sword"}));
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�ѳ�����\n");
                set("unit", "��");
                set("value", 1000);
        }
        init_sword(20);
        setup();
}

