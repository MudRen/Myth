// sanjie wujiang4.c

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
  "west" : __DIR__"wujiang3",
  "eastup" : __DIR__"wujiang5",
]));
  set("outdoors", 1);

  setup();
}
