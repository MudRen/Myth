// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ͨ��");
  set ("long", @LONG

ͨ�������ʯ��أ����߶����������������ݡ��ϱ��й�����
������������Ӣ���Ķ��ڣ�����������һ����Ķ�Ѩ��ͨ����
���������ȥ��

LONG);

  set("exits", ([
        "south"   : __DIR__"dongkou",
        "northwest"   : __DIR__"dongting",
        "east"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/xiniu"  : 1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object jing = present ("shoumen niujing", this_object());
  if (! who->query_temp("obstacle/jinping_give_hulu") &&
      jing &&
      dir == "east")
    return notify_fail ("����ţ��һ����ֻ��ţ�ǵ�ס�㣺���ﵽ�Ķ�ȥ��\n");
  return ::valid_leave(who, dir);
}

