// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "Ϧ�ֽ�");
  set ("long", @LONG

Ϧ�ֽ�Ϊ���Ϲ�ʳƷ���У����ݾ�¥��������ζ�˱ǡ�һȺȺʳ��
���ؽֽ������ҡ�������һ��д�ž������ƵľƵ꣬������һ����
�������ķ�¥��

LONG);

  set("exits", ([ 
    "north" : __DIR__"jiudian",
    "south" : __DIR__"fanlou",
    "west" : __DIR__"xi1",
    "east" : __DIR__"xi3",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
