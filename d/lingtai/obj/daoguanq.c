#include <armor.h>

inherit HEAD;

void create()
{
        set_name("��ľ����", ({ "bonnet", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��Ӳľ�ĵ��ڡ�\n");
                set("material", "steel");
                set("value", 100);
                set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
        }
        setup();
}

