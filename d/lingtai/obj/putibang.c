#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name("������", ({"puti zhang", "zhang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
		set("long", "һ�ѵ���ɫ����������ֻ��壬����Щ������\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
		set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
        init_stick(80);
        setup();
}

