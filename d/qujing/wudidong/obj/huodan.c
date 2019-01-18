
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "������һ�ɣ�Ǳ������ָ�们�䣡\n");
                set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
	    set("no_give", "��ô����ĵ�ҩ�����Լ����Űɣ�\n");
	}
	add_action("do_eat", "eat");
}

void create()
{
	set_name( HIC "Ǳ����" NOR , ({"dan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��Ѫ��ɫ�ĵ��裬��΢���ŵ�Щ��������\n");
		set("value", 10000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int pot,learned,dif;

	 pot=me->query("potential");
	 learned=me->query("learned_points");
	 dif=pot-learned;

	if (arg!="dan")	return 0;

	me->set("potential", pot+random(100-dif));

        message_vision(HIC "$N��������һ��Ǳ�����������У�һʱ���������硣\n" NOR, me);

	destruct(this_object());
	return 1;
}
