// sanjie tianyidian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��һ���");
  set ("long", @LONG
	
���ϵƻ�ͨ�����м���С��ʿæ�Ŵ�ɨ�ŵ��ϵ����������
���ﲢû��ʲô�˼�����Եø���������
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang1",
  "west" : __DIR__"tianyidian2",
  "east" : __DIR__"tianyidian3",
  "south" : __DIR__"tianyimen1",
]));
  set("outdoors", 0);

  setup();
}
