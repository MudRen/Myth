// Room: /u/mimi/zhuziguo/eaststreet2.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "��Ԫ��");
  set ("long", @LONG

��������Ԫ���жΣ�·���Լ������������С����������һ�Ҳ���
�꣬�ϱ���һ�ҿ͵ꡣ

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"square.c",
    "south" : __DIR__"kezhan.c",
    "east" : __DIR__"estreet",
  ]));
  set("objects", ([
      __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");                  

  setup();
}
