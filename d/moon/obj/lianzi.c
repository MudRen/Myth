
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"lian zi", "lianzi","lotus seed"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "�������ӣ�������������\n");
                set("unit", "��");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
