#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("����ذ��", ({"silver dagger", "dagger" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������ذ�ף��������൱����\n");
                set("value", 5000);
                set("material", "steel");
        }
        init_dagger(10, SECONDARY);
        set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n���뻳�С�\n");
        setup();
}

