// Room: /d/jjf/keting.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ſڹ���һ����ң����顸������˽���ĸ����֣�������������
���顣�����ҽ�վ�����ԡ��ؽ������ڵ��е�̫ʦ���ϣ���ŭ������
������������������ͷЦ��Ц��Ҳ������Ϊû����˵�������ϵ�
���պ����ࡣ
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone_road",
  "north" : __DIR__"front_yard2",
  "west" : __DIR__"side_keting",
  "east" : __DIR__"dining_room",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/jiajiang" : 2,
  __DIR__"npc/qinqiong" : 1,
]));
  set("valid_startroom", 1);

  setup();

  call_other("/obj/board/jjf_b", "???");
}
/*
int valid_leave(object me, string dir)
{
  if ((dir == "east") || (dir == "south") || (dir == "west") )
    {
      if (!(  ((string)me->query("family/master_name") == "�޳�")
	  ||  ((string)me->query("family/master_name") == "����"))
	  &&  objectp(present("qin qiong", environment(me)))
)
	return notify_fail("���������ã���������룿\n");
      return ::valid_leave(me, dir); 
    }
  return 1;
}
*/
