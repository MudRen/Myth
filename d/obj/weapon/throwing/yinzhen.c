// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({"yin zhen","zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "һ��ϸС���廨�룬���ŵ�㺮â��\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 5);
                set("value", 3);
        }
        set_amount(random(10)+1);
        init_throwing(10);
        setup();
}

