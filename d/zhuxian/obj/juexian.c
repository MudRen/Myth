#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIW "���ɽ�" NOR, ({ "juexian jian", "jian", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ɽ�\n"
);
                set("value", 0);
                set("sheenness", 25);
                set("material", "silver");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("is_monitored", 1);
                set("no_put", 1);
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(125);
        setup();
}
