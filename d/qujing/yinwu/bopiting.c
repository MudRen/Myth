// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ƥͤ");
  set ("long", @LONG

ɽ����һ������ʯͤ��ͤ��������������̦��ͤ����ʯ��ʯ��
ʯ�ʡ�������ͨ�������԰���������쾮�����������ã�����
����һ��Ѩ��ڡ�

LONG);

  set("exits", ([
        "north"    : __DIR__"houyuan",
        "west"    : __DIR__"zhong",
        "east"    : __DIR__"tianjing",
        "southeast"    : __DIR__"rouku",
      ]));
  set("objects", ([
        __DIR__"npc/yaojing" : 2,
      ]));
  setup();
}

int valid_leave (object who, string dir)
{
  object yaojing = present("yao jing", this_object());

  if (dir != "west")
    return ::valid_leave(who,dir);

  if (yaojing &&
      (! who->query_temp("apply/name") ||
       who->query_temp("apply/name")[0] != "������"))
    return notify_fail("��ͤ����һ�ѽ������ؾ�ס����������\n");
  return ::valid_leave(who,dir);
}
