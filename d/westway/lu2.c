inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","ɽ����");
  set ("long", @LONG

ɽ����ں����ģ��������������ȳ�ζ������ɽ�������ͨ��
������������˿���֣��ƺ��ڿ����硣
LONG);

  set("exits", ([
        "south" : __DIR__"lu1",
        "north"      : __DIR__"lu3",
      ]));
//  set("outdoors", __DIR__);

  setup();
}





