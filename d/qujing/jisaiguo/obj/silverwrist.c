#include <armor.h>

inherit WRISTS;

void create()
{
        set_name("������", ({ "silver wrist", "wrist" }));
        set("weight", 500);
        set("long", "һ������Ӳӵ�����\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N��$n�׵������ϡ�\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

