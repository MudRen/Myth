//Cracked by Kafei
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIC "������" NOR, ({"mati lian", "ma"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������ŵ�������������������ͬ�ģ��������⣬ʥ���ϡ�\n");
		set("unit", "��");
		set("value", 35);
		set("base_unit", "��");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"