// bigaxe.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(HIW"��"NOR, ({ "gui fu","fu","axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
		set("long", WHT"�Ϲ�ʮ�����֮һ��������˵�Ǵ�����ˮʱ�ù��ġ�\n"NOR);
		set("value", 0);
                set("no_put",1);
                set("no_zm",1);
		set("wield_msg", "$N�ó�һ��$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_axe(100+random(100), TWO_HANDED);
	setup();
}
