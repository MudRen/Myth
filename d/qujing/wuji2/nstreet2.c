// Room: /u/mimi/zhuziguo/northstreet2.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "ǬԪ��");
  set ("long", @LONG

ǬԪ�ֱ��ζ�Ϊ���ڹ�Ա�ĸ�ۡ��������̫�Ӹ�����������ʦ����
�����������ڼ����Ļʹ��ˡ�

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "south" : __DIR__"nstreet",
    "east" : __DIR__"house.c",
    "north" : __DIR__"zym.c",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "east" && !interactive(who))
    return 0;
  return ::valid_leave(who, dir);
}

