#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ľ�師", ({ "famuaxe" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("long", "����һ�ѳ��صĴ�師�����������ǳ�˳�֡�\n");
                set("value", 200);
                set("no_put", 1);
                set("no_drop", 1);
                set("wield_msg", "$N�ó�һ��$n���������е���������\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_axe(25, TWO_HANDED);
        setup();
}
