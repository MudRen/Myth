// Room: /u/mimi/zhuziguo/houzaimen.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������ƫ�ţ�����ȥ��������ģ�ֻ�м�����̫����������
�����Ƕ����˯��

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"jxt",
    "south" : __DIR__"wall.c",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
  ]));

  setup();
}

