// Room: /u/mimi/zhuziguo/huilang.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�������");
  set ("long", @LONG

����������ɰ���ʯ��ɣ�������㣬Ī��ά��άФ������֮�⻨
���ƽ������ⰻȻ������ͨ������ͤ��������������̳��

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"jxt.c",
    "south" : __DIR__"palace",
    "north" : __DIR__"huilang2.c",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
