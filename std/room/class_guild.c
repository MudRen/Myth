//Cracked by Roath
// guild.c

inherit ROOM;

void setup()
{
	::setup();
}

void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me;

	me = this_player();
	if( stringp(me->query("class")) )
		return notify_fail("���Ѿ��μ����������ᡣ\n");
	me->set("class", "fighter");
	me->set("startroom", CLASS_D("fighter") + "/guildhall");
	write("\n��ϲ���ӽ��������Ѿ���Ϊһ�����ߣ�\n\n");
	return 1;
}

