// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

һ����ڻԻ͵Ĵ��ţ�������һ�������Ϸ����ơ���ǰ���Ҹ���һֻ
��ʯ��������������������������Ϲ��Ļʹ����ų��������Ͻ֣���
���ǻ����ӡ�

LONG);
  set("exits", ([ 
    "west" : __DIR__"hugong1",
    "east" : __DIR__"hugong2",
    "north" : __DIR__"zhuzi5",
    "south" : __DIR__"qian",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 4,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;
  return ::valid_leave(who, dir);
}
