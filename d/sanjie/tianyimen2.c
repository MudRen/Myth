// sanjie tianyimen2.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
�����Ǻ�ΰ�ġ���һ������ǰ�������һ�����أ����û��
ʦ������׼���κ��˶����ܴ�����ͨ����
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilu4",
  "south" : __DIR__"tianyidian4",
]));
  set("outdoors", 1);
  setup();
}
