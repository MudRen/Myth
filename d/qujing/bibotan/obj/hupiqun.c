#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("��Ƥ����", ({ "tiger surcoat","surcoat" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����Ƥ�����磬������������൱���硣\n");
                set("material", "cloth");
                set("unit", "��");
                set("armor_prop/armor", 5);
		set("armor_prop/dodge", 5);
		set("armor_prop/armor_vs_force", 50);
		set("armor_prop/armor_vs_spells", 50);
		set("msg_wear", "$N����һ��$n��\n");
		set("msg_remove", "$N����$n��\n");
		set("armor_prop/personality", 3);
                set("armor_prop/spirituality", 3);
        }
        setup();
}

