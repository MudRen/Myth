// created by snowcat.c 4/4/1997
// room: /d/nuerguo/towna3.c

inherit ROOM;

void create ()
{
  set ("short", "�����ﶫ");
  set ("long", @LONG

������������İ����ﶫ��������һ�³����ĳ�ǽ��������
����������������ڵء�Ů������������Χ��һ��̸����
�����������µ�����һ�¡�

LONG);

  set("exits", ([
        "west"  : __DIR__"towna2",
        "south" : __DIR__"townb3",
    ]));
  set("outdoors", __DIR__"");

  setup();
}






