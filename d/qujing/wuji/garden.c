// Room: /u/mimi/zhuziguo/garden.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ������һ��С���������˼�ֻ�ס���Χ��ǰ���˲����ɰأ���  
���дС�

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "west" : __DIR__"house.c",
    "south" : __DIR__"bedroom.c",
    "east" : __DIR__"stable.c",
    "north" : __DIR__"shufang.c",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
