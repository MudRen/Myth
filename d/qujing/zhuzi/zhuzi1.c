// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

���Ÿ��ʣ���ͷ��Ʈ��һ�ӻ��죬���顰���Ϲ�������������һ��
�Ǻӣ�������һ˫������ľ���ţ��ɴ������������Ŷ���󣬷���
���������š�

LONG);

  set("exits", ([ 
    "north" : __DIR__"dalu2",
    "south" : __DIR__"zhuzi2",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "north")
    return 0;
  return ::valid_leave(who, dir);
}
