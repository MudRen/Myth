#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("��¨", ({ "zhu lou", "lou" }) );
        set_weight(1000);
        set_max_encumbrance(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bamboo");
		set("value", 50);
		set_max_items(5);
                set("armor_prop/armor", 1);
		set("wear_msg", "$N��$n�����˱���\n");
                set("long", "һ������¨�����Ա��ڼ��ϡ�\n");
        }
        setup();
}

