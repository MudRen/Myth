//Cracked by Roath
// piao.c ˮư

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ˮư", ({ "piao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ˮư����֪���ܳ˶���ˮ����������ʹ���о����ܲ���\n");
		set("value", 0);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(10);
	setup();
}
