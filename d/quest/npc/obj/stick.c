// bintiegun.c

#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
	set_name(RED"������"NOR, ({ "pili gun","stick", "gun" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);

		set("material", "steel");
		set("long", HIW"�Ϲ�ʮ�����֮һ��������\n"NOR);
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
        init_stick(80+random(30));
	setup();
}
