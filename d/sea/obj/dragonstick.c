#include <weapon.h>

inherit STICK;

void create()
{
        set_name("������", ({ "dragon stick","gun", "bang" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("long", "һ���������������ĳ�����\n");
                set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
                set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
        init_stick(50);
        setup();
}

