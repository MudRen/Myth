
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ź", ({"lian ou", "ou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "���۵���ź��ɢ�������˵����㡣\n");
                set("unit", "��");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
