// jadesword.c

#include <weapon.h>
inherit SWORD;
#include <ansi.h>

void create()
{
        set_name(HIG"������"NOR, ({ "jadesword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һ֧��������ĳ���");
                set("value", 20000);
                set("material", "steel");
        }
        init_sword(130);

        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

        setup();
}

