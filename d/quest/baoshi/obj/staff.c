// tieguai.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(CYN"����"NOR, ({ "fo zhang","staff","zhang" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);

		set("long",CYN"�Ϲ�ʮ�����֮һ�����ȣ\n"NOR);
		set("value", 0);
		set("material", "steel");
	}

        init_staff(80+random(20));
	setup();
}
