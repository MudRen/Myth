// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯǽ");
  set ("long", @LONG

ǽ�����棬�߸ߵ�ʯǽ�£���һ��խ��ͨ����С·һ�㣬����
�ȵý��ʵʵ��

LONG);

  set("exits", ([
        "east"   : __DIR__"shi4",
        "west"   : __DIR__"menlou",
      ]));
  set("outdoors", __DIR__);

  setup();
}



