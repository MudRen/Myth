// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "·��");
  set ("long", @LONG

��������������·�������ͨ����Ȯ��һ���ʯ���£�����
��·��ɭɭ���¡�·�ڱ�һȦ�ڿ���С��ʯ��������Ȼ��ʯ��
ʯ��һ�㡣

LONG);

  set("exits", ([
        "northwest"    : __DIR__"xuanya5",
        "northeast"    : __DIR__"xuanya3",
        "west"    : __DIR__"caopo1",
        "southwest"    : __DIR__"caopo3",
        "southeast"    : __DIR__"caopo2",
      ]));
  set("objects", ([
        __DIR__"npc/shanyao" : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  object shanyao = present("shan yao", this_object());

  if (dir == "west" || dir == "southwest" || dir == "southeast")
    return ::valid_leave(who,dir);

  if (! who->query("env/invisibility") &&
      shanyao &&
      ! shanyao->is_busy() &&
      ! shanyao->query_temp("no_move"))
    return notify_fail("ɽ���������������������\n");
  return ::valid_leave(who,dir);
}
