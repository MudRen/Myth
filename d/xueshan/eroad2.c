//standroom.c used by weiqi...others may hate this format:D
//eroad2.c

inherit ROOM;

void create ()
{
	set ("short", "Сľ����");
	set ("long", @LONG

����������Щľͷ�Ǵ��������ġ����������ȷ��һ��Сľ�ݡ�
��Χ��һ�����Ƶ�Χǽ��Ҳ�����������ߡ�Χǽ��ڳ�վ��һ
λ�������ۣ������䵶�����ӡ�
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"icegate",
		"west" : __DIR__"eroad1",
		"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/shier" : 2,
	]));


	set("outdoors", "xuesan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

int valid_leave(object me, string dir)
{
	object shier;
	if (dir == "south" ) {
		if(objectp(shier=present("shier", environment(me))) && living(shier) )
		{
			if ( me->query("family/family_name") == "��ѩɽ" && (int)me->query("family/generation") <= 3 )
				write("�̶���ͷ�����ذ������˽�ȥ��\n");
			else 
				return notify_fail("�̶�����һ��������������κ��˲������ڴ����\n");
		}
	}

	return ::valid_leave(me, dir);
}

