//Cracked by Roath
#include <weapon.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name( "������", ({ "green ruyi", "ruyi", "dagger" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ī��ɫ�����⣬˳�������ɲ�����״��\n");
                set("value", 0);
                set("no_sell",1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
				set("replace_file", "/d/obj/weapon/dagger/dagger");
                set("wield_msg", "$N�ó�$n�������ϡ�\n");
        	set("weapon_prop/karma", 5);
                set("material", "wood");
        }
        init_dagger(15);
        set("is_monitored",1);
        setup();
}
