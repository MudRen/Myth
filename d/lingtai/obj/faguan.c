#include <armor.h>

inherit HEAD;

void create()
{
        set_name("��ʦ����", ({ "loyal bonnet", "bonnet", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ����ɫ�����񷨹ڡ�\n");
                set("material", "steel");
                set("value", 1000);
		set("no_sell", 1);
                set("armor_prop/armor", 3);
		set("armor_prop/intelligence", 3);
		set("armor_prop/personality", 1);
        }
        setup();
}

