inherit ROOM;

void create ()
{
  set ("short", "�཭��");
  set ("long", @LONG

���޹཭�ڣ���ˮ���ˣ���Ȼ������������һ����������
�ֺ裬�ſ��а��ŵĹ��У��������ݵ�Ѳ�������ܡ�������
һ��Ƭ���꣬��ˮԶԶ��������ʡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guipan" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/changan/eside4",
  "enter" : __DIR__"temple",
]));

  setup();
}

int valid_leave(object me, string dir)
{      object gui;
       if (dir=="enter" && 
           objectp(gui=present("gui pan",environment(me)))
           && living(gui) && 
	   member_array("gui pan",me->parse_command_id_list())==-1 )
	   return notify_fail("���г�����һ����߾������үү�����˭���Ҵ���\n");
       return ::valid_leave(me,dir);
}



