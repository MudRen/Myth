// yinqiang.c
// updated 5-30-97, pickle

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit SPEAR;

void create()
{
        set_name(HIW "����ǹ" NOR, ({"silver spear", "qiang", "spear"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰѳ��صĳ�ǹ��ǹ���Ǵ������ƣ������ޱȣ�\n");
                set("value", 18000);
                set("material", "silver");
				set("replace_file", "/d/obj/weapon/spear/tieqiang");
                set("wield_msg","$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(70);
        setup();
}

