// glass.c

inherit EQUIP;

void create()
{
	set_name("ս����̽����", ({ "detector", "glass", "device" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		"�������ԡ������项��ս����̽�����������������̽��(detect)����\n"
		"��ս������\n");
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"ͷ��":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("��Ҫ̽��˭��ս������\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("̽������ʾ%s��ս�����ǣ�%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

