// sanjie tianyidian2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
	
���ϵƻ�ͨ�����м���С��ʿæ�Ŵ�ɨ�ŵ��ϵ����������
���ﲢû��ʲô�˼�����Եø���������
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang2",
  "east" : __DIR__"tianyidian1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/huanwangzi": 1 ]) );

  setup();
}
