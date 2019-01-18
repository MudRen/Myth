// Room: /u/mimi/zhuziguo/princehouse.c
inherit ROOM;

void create ()
{
  set ("short", "̫�Ӹ�");
  set ("long", @LONG

�˴�����̫�ӵ��й�������ǰ��������Ϊ̫���Ѿ����ˣ���Ϊ����
�칬�ϰ�����䣬û��گ�����˽�Խ�����������ġ�

LONG);

  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"nstreet2",
    "northeast" : __DIR__"shufang.c",
    "east" : __DIR__"garden.c",
  ]));
  set("objects", ([
    __DIR__"npc/siwei" : 2,
  ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "west" && !interactive(who))
    return 0;
  return ::valid_leave(who, dir);
}

