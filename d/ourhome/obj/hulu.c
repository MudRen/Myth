// hulu.c  ��«

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���«", ({"hulu"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��װˮ�Ĵ��«��\n");
		set("unit", "��");
		set("value", 10);
		set("max_liquid", 50);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 40,
		"drunk_apply": 20,
	]));
}
