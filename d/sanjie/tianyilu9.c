// sanjie tianyilu9.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��һ·");
  set ("long", @LONG
	
		��һ���ء�û����׼
		
		���Խ��롡������Ǵ

һ���ڲ�¡����ɽ��������ʲô�������������ȥ��������
���£���������һ�����أ������߰ɡ�
LONG);

  set("exits", ([ 
  "north" : __DIR__"tianyidong1",
  "southdown" : __DIR__"tianyilu8",
]));
  set("outdoors", 1);

  setup();
}
