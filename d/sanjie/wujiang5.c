// sanjie wujiang5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�ڽ���");
  set ("long", @LONG
	
		����������������
		��������ָ·�ƣ�
		����������������
	
			���絺
			����
		�ڽ��ߡ����ڴˡ���ʬ��

�����ڽ�ˮ���˻��Ĵ��Ű��ߣ��׻������˻�������ˬ�Ŀ�
�������˶�ʱ���������������﷢����һ�α��ҹ��¡�
LONG);

  set("exits", ([
  "westdown" : __DIR__"wujiang4",
  "northup" : __DIR__"shanlu1",
  "eastdown" : __DIR__"wujiang6",
]));
  set("outdoors", 1);

  setup();
}
