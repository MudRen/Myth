// jianpu.c	��������

inherit ITEM;

void create()
{
	set_name("��������", ({ "jian pu", "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������������ͼ�⣬����Ѿ���Щ�����ˡ�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":		"sword",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
								// to learn this skill.
			"sen_cost":	30,			// gin cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	40			// the maximum level you can learn
								// from this object.
		]) );
	}
}
