// ǧ�ϻ��츫 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(WHT"����������"NOR, ({"huitian axe", "fu", "axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                      "�������ǧ����Ĵ�ͷ�䲻˵�������,��һ���һ��������n");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("material", "iron");
                set("wield_msg",
                           "$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

   init_axe(100);
        setup();
}

