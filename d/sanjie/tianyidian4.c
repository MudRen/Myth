// sanjie tianyidian4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG
	
���ϵƻ�ͨ�����м���С��ʿæ�Ŵ�ɨ�ŵ��ϵ����������
���ﲢû��ʲô�˼�����Եø���������
LONG);

  set("exits", ([
  "north" : __DIR__"tianyimen2",
  "west" : __DIR__"tianyilang4",
  "east" : __DIR__"tianyilang5",
  "south" : __DIR__"tianyilang1",
]));
  set("outdoors", 0);
  set("objects", ([
  "/obj/zhangmen/sanjie": 1,
                __DIR__"npc/zhaoyang": 1 ]) );

  setup();
}
