// changqiang.c

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
	set_name(YEL"ħǹ"NOR, ({ "mo qiang","qiang","spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
                set("no_put",1);
		set("material", "wood");
		set("long", HIC"�Ϲ�ʮ�����֮һ��ħǹ\n"NOR);
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
	//	set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
        init_spear(85+random(20));
	setup();
}
