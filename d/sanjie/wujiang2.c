// sanjie wujiang2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�ڽ���");
  set ("long", @LONG
	
�����ڽ�ˮ���˻��Ĵ��Ű��ߣ��׻������˻�������ˬ�Ŀ�
�������˶�ʱ���������������﷢����һ�α��ҹ��¡�
LONG);

  set("exits", ([
  "west" : __DIR__"wujiang1",
  "east" : __DIR__"wujiang3",
]));
  set("outdoors", 1);

  setup();
}
