// sanjie wujiang6.c

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
  "westup" : __DIR__"wujiang5",
  "east" : __DIR__"wujiang7",
]));
  set("outdoors", 1);

  setup();
}
