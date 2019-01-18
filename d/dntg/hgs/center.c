// Room: /d/4world/center.c
inherit ROOM;

void create ()
{
  set ("short", "����̨");
  set ("long", @LONG

������ǰ������ĳ����İ��ƹ㳡���������Ĵ�·�ɴ�������
����˷����ɿ��������и��ص���������������һ�ɷ�������
��������ש�̾ͣ�����һ����̨��̨�����Ÿ����(qigan)��ʱ��
�������ڳ���յ��ϱ��ݡ�
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "qigan" : "һ����ͩľ������ˣ��������ɡ�

",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yiren" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"north1",
  "west" : __DIR__"west1",
  "east" : __DIR__"east1",
]));

  setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "qigan") ))
                return notify_fail("��Ҫ��ʲô��\n");
	
	message_vision("$N���˴��֣��ڵؾ�˳�����������ȥ��\n",me);

	if((int)me->query_skill("dodge",1) < 20) {
		me->improve_skill("dodge", 5);
		me->receive_damage("kee", 10);

	}	
	else {
		message_vision("$N�����������������Χһ��Ȳɣ�\n", me);
	}
   return 1;
}

