// hulu.c  ˮ��

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"ˮ��"NOR, ({"shui bei","bei"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��װˮ�ı��ӡ�\n");
		set("unit", "��");
		set("value", 10);
		set("max_liquid", 50);
	}

	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 40,
		"drunk_apply": 20,
	]));
}
