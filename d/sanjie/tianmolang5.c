// sanjie tianmolang5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
��ħ�����ȣ���������Ҫ��������һЩ��֪����ʲô�Ķ���
�������
LONG);

  set("exits", ([
  "east" : __DIR__"tianmodian5",
  "west" : __DIR__"tianmolang4",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/moshuai": 1 ]) );

  setup();
}
