// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name(HIY "����ǹ" NOR, ({"yin qiang", "qiang", "spear"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ǰѳ��صĳ�ǹ��ǹ���Ǵ������ƣ������ޱȣ�\n");
                set("value", 50000);
                set("material", "iron");
                set("wield_msg",
"$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(90);
        setup();
}

