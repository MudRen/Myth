//Cracked by Roath
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��Ҷ", ({ "he ye", "heye", "sword" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("value", 700);
                set("material", "steel");
                set("long", "һƬ���̵ĺ�Ҷ��\n");
                set("wield_msg", "$N����һƬ$n��\n");
                set("unwield_msg", "$N��$n����һ�ߡ�\n");
        }
        init_sword(40);
        setup();
}

