//Cracked by Roath
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("���浶", ({"huoyan dao", "dao", "blade"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",10000);
		set("no_sell", 1);
                set("material", "iron");
                set("long", "����һ���Զ�һ��Ļ��浶��\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(60);
        setup();
}

