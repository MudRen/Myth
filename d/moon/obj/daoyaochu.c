#include <weapon.h>

inherit HAMMER;
void create()
{
        set_name("��ҩ��", ({ "yao chu", "chu" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ճ�������ҩ�����ơ�\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(25);
        setup();
}

