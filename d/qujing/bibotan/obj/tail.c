#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("��β��", ({ "whip"}) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��ϸ���ı���β�͡�\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg", "$N�����н���һ��$n�������\n");
                set("unwield_msg", "$N��$n�������С�\n");
        }
        init_whip(25);
        setup();
}

