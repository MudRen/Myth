#include <weapon.h>

inherit STICK;

void create()
{
        set_name("������", ({ "guteng zhang","zhang","gun", "bang" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "һ����ƮƮ��ɫ�����ȡ�\n");
                set("wield_msg", "$N����һ��$n�������С�\n");
                set("unwield_msg", "$N��$n��غ�����\n");
        }
        init_stick(10);
        setup();
}

