// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"ǧ����֥"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ���������ǧ����֥����˵��һ�ÿɵ�500���飬200Ǳ�ܡ�\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
	message_vision("$N����һ��ǧ����֥��ֻ�����Լ��ֱ�������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

