#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("��������ǹ", ({"sanliang spear", "spear"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ǹ���Ƕ�������Ķ��ű����������ޱȡ�\n");
                set("value", 20000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(80);
        setup();
}

