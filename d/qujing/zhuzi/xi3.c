// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "Ϧ�ֽ�");
  set ("long", @LONG

Ϧ�ֽ�Ϊ���Ϲ�ʳƷ���У����ݾ�¥��������ζ�˱ǡ�һȺȺʳ��
���ؽֽ������ҡ����������������Ĳ跿���ϱ������Ϲ���һ�Ҵ�
���̡�

LONG);

  set("exits", ([ 
    "north" : __DIR__"chafang",
    "south" : __DIR__"mipu",
    "west" : __DIR__"xi2",
    "east" : __DIR__"xi4",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
