//standroom.c used by weiqi...others may hate this format:D
//wuchang-c.c

inherit ROOM;

void create ()
{
	set ("short", "�����䳡");
	set ("long", @LONG

���Ǳ���ǰ��һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹��򡣶����һ�����Ӷ���һ�ɴ���ȽȽ��������ǳ�
���ˡ�������ѩɽ���ӵ���Ϣ����
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-s",
		"north" : __DIR__"wuchang-n",
		"west" : __DIR__"wuchang-w",
		"east" : __DIR__"wuchang-e",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/xunshi" : 2,
		__DIR__"npc/yingwu-guai" : 1,
		"/d/obj/misc/ice.c" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_skate", "skate");
	add_action("do_skate", "huabing");
	add_action("do_skate", "hua");
}

int do_skate(string arg)
{
	int point;
	int gainfactor; //set the dodge level can be obtained by skating.
 	object me = this_player();

	gainfactor = 1;
	if( (int)me->query_skill("dodge", 1) > 50 ) gainfactor = 0;

	point = 5 + me->query("max_kee")*5/100;

	if( me->query("kee") < (int)me->query("max_kee")/4 )
	{
		message_vision("$N������������һ��...���ˤ�˸��Ľų��졣\n", me);
		return 1;
	}      
	if( me->query("sen") < (int)me->query("max_sen")/4 )
	{
		message_vision("$N������������һ��...���ԭ��ת�˼�Ȧ��ͷ��֮�¸�æſ�ڱ��ϣ���Ҳ���Ҷ�����\n", me);
		return 1;
	}      

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-n");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 1.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go west.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-nw");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 2.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N�˸߲��ң��������������ϻ��˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-w");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 3.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N�˸߲��ң��������������ϻ��˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-sw");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 4.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go east.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-s");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 5.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go east.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-se");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 6.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-e");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 7.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go north.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-ne");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 8.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go west.
	message_vision("$N�˸߲��ң������������������˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-n");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 9.

//need construct the followwing section as another function?dunno how yet...weiqi.
	//go south.
	message_vision("$N�˸߲��ң��������������ϻ��˹�ȥ��\n", me);
	me->move(__DIR__"wuchang-c");
	me->receive_damage("kee", point);
	me->improve_skill("dodge", (1+random(point/2))*gainfactor);
	message_vision("$N��������شӱ��ϳ��˹�����\n", me);

	if( (me->query("kee") < (int)me->query("max_kee")/4) || 
	    (me->query("sen") < (int)me->query("max_sen")/4) ){
		message_vision("������գ�һ��ˤ�˸��Ľų��죡\n", me);
		return 1;
	}
//end of section 10.

	message_vision("$N���������ڣ����ȵ�ͣ��������\n", me);
	return 1;
}

