// hu-blade.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("����", ({ "hu-blade" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������ĺ���");
                set("value", 2000);
                set("material", "steel");
        }
        init_blade(30);

        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

        setup();
}

