// An example book

inherit ITEM;

void create()
{
	set_name("����ȭ��Ҫּ", ({ "book" }));
	set_weight(600);
	set("unit", "��");
	set("long",
		"����һ����������ȭ���������飬����ȭ����ѩͤ������ȭʦ�洫��ȭ��\n"
		"����ѧ�׶����Ȿ����Ȼֻ����������ȭ�����ŵĹ�\�򣬵�������������\n"
		"���㲻���ˣ��ʺϳ�ѧ�ߡ�\n");
	set("value", 100);
	set("skill", ([
		"name": 		"liuh-ken",		// name of the skill
		"exp_required":	0,				// minimum combat experience required
										// to learn this skill.
		"sen_cost":		40,				// gin cost every time study this
		"difficulty":	20,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	10				// the maximum level you can learn
										// from this object.
	]) );
}
