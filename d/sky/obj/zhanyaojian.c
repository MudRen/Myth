// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("ն����", ({ "zhanyao jian","jian", "sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������Ž��ĳ�����\n");
		set("value", 8000);
		set("material", "gold");
		set("weapon_prop/courage", 10);
	}
	init_sword(70);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");

// The setup() is required.

	setup();
}
