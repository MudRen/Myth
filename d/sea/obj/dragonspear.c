#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("����ǹ", ({"dragon spear", "qiang", "spear"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ǣ���â����\n");
                set("value", 5000);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������У�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(50);
        setup();
}

