//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("�׹���", ({"leigong chu", "chu"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
		set("no_sell", 1);
                set("material", "wood");
                set("long", "һ�Ѽ�ͷ�׹��ơ�\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������\n");
        }
        init_staff(60);
        setup();
}

