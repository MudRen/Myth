//Cracked by Roath
// zui.c ��������

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
    set_name(HIG"��������"NOR, ({"zui", "realzui", "bottle"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��˵������,������������һ�а��ˡ�\n");
		set("unit", "ƿ");
		set("value", 5000);
		set("realzui",1);
		set("max_liquid", 500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 400,
		"drunk_apply": 400,
	]));
}
