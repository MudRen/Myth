// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dianmen.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������۵ĵ��ţ����ź�ľ���ܷ���һ�£��ſ�֯������
�����ж�ʮ�������֣�����˳�����Ըף���������������庣
�̣��������������ꡣ��

LONG);

  set("item_desc", ([
        "east" : (: look_door, "east" :),
      ]));
  set("exits", ([
        "southdown"    : __DIR__"banlu1",
        "west"         : __DIR__"zhai",
        "east"         : __DIR__"wugu",
        "north"        : __DIR__"sanqing",
      ]));
  set("objects", ([
        __DIR__"npc/daozhang"    : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  create_door("east", "С��", "west", DOOR_CLOSED);
  setup();

}

