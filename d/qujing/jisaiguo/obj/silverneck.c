#include <armor.h>

inherit NECK;

void create()
{
        set_name("������", ({ "silver necklace", "necklace" }));
        set("weight", 500);
        set("long", "һ������Ӳӵ�����������Ů��ϲ�������\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N����һ��$n��\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

