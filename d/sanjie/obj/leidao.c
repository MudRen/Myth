// zileidao.c �����׵�

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC"�����׵�"NOR, ({"diyu leidao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ�Ĵ󵶣�������������ë������\n");
                set("value", 2500);
                set("material", "gold");
                    set("no_sell", 1);
                set("wield_msg", MAG"$N��ৡ���һ�����һ��$n"NOR+MAG"�������У����ױ�����\n"NOR);
                set("unwield_msg", MAG"$N�����е�$n"NOR+MAG"���¡�\n"NOR);
        	set("weapon_prop/courage", 150);
        	set("replace_file", "/d/sanjie/obj/jindao");

        }
        init_blade(100);
        setup();
}

