//Cracked by Roath
// mifan.c �׷�
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�׷�", ({"mifan"}));
	set_weight(240);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������ӡ�\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 25);
	}
}
