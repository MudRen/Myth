#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIC"��"NOR, ({ "shen chui","chui","hammer" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", MAG"�Ϲ�ʮ�����֮һ���񴸡�\n"NOR);
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);

                set("material", "wood");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(80+random(20));
        setup();
}

