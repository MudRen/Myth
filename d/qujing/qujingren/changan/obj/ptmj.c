// ptmj.c ��������

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�¹Ɑ", ({"ptmj", "yueguangbei", "bei"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����¹Ɑ\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "��������",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}

