//Cracked by Roath
#include <weapon.h>

inherit AXE;

void create()
{
        set_name("���и�", ({ "iron axe", "axe" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ص���������������\n");
                set("value", 500);
                set("wield_msg",
"$N�ó�һ�ѿ����õ�$n���������е���������\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_axe(30, TWO_HANDED);
        setup();
}

