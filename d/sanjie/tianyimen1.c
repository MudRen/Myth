// sanjie tianyimen1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��һ����");
  set ("long", @LONG
	
			����������
			����һ����
			����������

һ����ΰ�Ĺ������ǰ��������ǰ�����ʯ�Ʒ����Ǹ��а�
�ɣ��Ʒ���д�Ŵ��������֡�������һ����
LONG);

  set("exits", ([
  "north" : __DIR__"tianyidian1",
  "southdown" : __DIR__"tianyilu3",
]));
  set("outdoors", 1);

  setup();
}
