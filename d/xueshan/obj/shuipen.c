
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮ��", ({"shui pen", "pen"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����������װˮ��С�衣\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 30);
	}

	set("liquid", ([
		"type": "water",
		"name": "ѩˮ",
		"remaining": 20,
	]));
}
