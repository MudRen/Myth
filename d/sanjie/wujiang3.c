// sanjie wujiang3.c

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
  "west" : __DIR__"wujiang2",
  "east" : __DIR__"wujiang4",
]));
  set("outdoors", 1);

  setup();
}
