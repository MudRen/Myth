// Room: /changan/nanyue.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ·�������ѵ���ɽ�ؽ硣��ɽ�ų��������۾����죬���ư��硣���Ի�
���Ϊ�ף�������´ɽΪ�㣬��С��ʮ�����������ư˰����Ȼ��˵�
�Թ�����⺷�������洦���У��ڴ����߿ɵ�С��Ϊ�ǡ�
LONG);

 set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/huang" : 1,
]));
set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway2",
  "south" : __DIR__"broadway3",
  "southeast" : "/d/meishan/guanjiang1",
]));

  setup();
}






