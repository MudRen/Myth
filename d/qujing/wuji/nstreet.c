// Room: /u/mimi/zhuziguo/northstreet.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ǬԪ��");
  set ("long", @LONG

ǬԪ�����߶�Ϊ��լ�񷿡����߿�ֱ��ʹ���·����ʱ������Ѳ
�ߡ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"square",
    "north" : __DIR__"nstreet2.c",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
