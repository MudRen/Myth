// sanjie wujiang9.c

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
  "west" : __DIR__"wujiang8",
  "down" : __DIR__"cangshirest",
  "eastup" : __DIR__"shanlin1",
]));
  set("outdoors", 1);

  setup();
}
