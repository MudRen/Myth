// created by snowcat.c 4/4/1997
// room: /d/nuerguo/towna1.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

������������İ���������������һ�³����ĳ�ǽ��������
����������������ڵء�Ů������������Χ��һ��̸����
�����������µ�����һ�¡�

LONG);

  set("exits", ([
        "east"  : __DIR__"towna2",
        "south" : __DIR__"townb1",
    ]));
  set("outdoors", __DIR__"");

  setup();
}






