#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ͷ��", ({ "dragon staff", "staff" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"һ���ִ��ֳ������ȣ�����һ��ͷ����Χ��������ͭ����\n");
                set("value", 5000);
                set("material", "brass");
                set("wield_msg", "$N�ó�һ������Ȼ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(50);
        setup();
}

