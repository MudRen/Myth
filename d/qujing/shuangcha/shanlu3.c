//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

����ط��Ѿ����Կ��������Եĳ�·�ˣ���ɫ����������ˣ�
���Ե����������죬��������Щ·���Զ���ЩҰ����ʯͷ
������䣬���˸е��칤����ʡ�
LONG);

  set("exits", ([
        "eastdown" : __DIR__"shanlu2",
        "west"   : __DIR__"on",
      ]));
  set("outdoors","sc");
  setup();
}
