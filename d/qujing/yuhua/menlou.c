// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

һ����¥�ϱ����裬¥����һͨ�������Ŷ�����¥���߶�
�������˸߸ߵ�ʯǽ����¥�������Ʈ�ǽ����һ���ң�
���ء�

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaolu11",
        "south"   : __DIR__"xiaojie1",
        "west"   : __DIR__"shi2",
        "east"   : __DIR__"shi3",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "north")
    return 0;

  return ::valid_leave(who,dir);
}



