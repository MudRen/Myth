//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

���߰�ʯ��㣬�����֣��������ޣ��ݺ����������̦޺�ɰߣ�������
ӳ������΢¶��С����
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"ontop.c",
  "north" : __DIR__"road2",
]));
  set("objects",(["/d/obj/flower/yehua.c":1,]));

  setup();
}






