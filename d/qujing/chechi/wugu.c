// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/wugu.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "����ֻ�");
  set ("long", @LONG

���������������ǽ�ڳ�ʪ�������ƺ�ʲôҲ�����塣�ſ���
����������ð��Ũ�̣�������һС�ʣ��������һ��һ���Ĵ�
�ڲ�ֽ��

LONG);

  set("item_desc", ([
        "west" : (: look_door, "west" :),
      ]));

  set("exits", ([
        "west"         : __DIR__"dianmen",
      ]));

  create_door("west", "С��", "east", DOOR_CLOSED);
  setup();
}

