// ������ bbs 8-17-98

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

����һ��Сʯ�ң���ʰ�úܸɾ�����Ȼ�ڵ��£�ȴ�ƺ�һ���Ҳ�����ơ�
һ��Сʯ���Ϸ���һյ���ŵ��͵�(light)��
LONG);

	set("item_desc", ([
		"light" : "һյ�谵���͵ƣ���ͭ�ĵ����ƺ�����������һ��\n�������ԣ������������ת(turn)����\n",
	]));
	set("exists", ([
		"up" : __DIR__"dragon-room",
	]));
	set("ligh_up", 1);
	set("door_locked",0);

	setup();
}

void init()
{
	add_action("do_turn", "turn");
}

int do_turn()
{
	object me=this_player();

	message_vision("$Nת��һ�µ�����",me);
	if(query("door_locked")) {
		message_vision("��������������������������\n",me);
		set("door_locked", 0);
		set("exits/up", __DIR__ "dragon-room");
	}
	else {
		message_vision("������������һ����\n",me);
		set("door_locked", 1);
		delete("exits/up");
	}
	return 1;
}

