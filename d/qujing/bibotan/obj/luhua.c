#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("«����", ({ "luhua cao", "cao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��ϸ����«���ݣ����Ʈ�ڡ�\n");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��ϸ����«�����������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_whip(1);
        setup();
}

