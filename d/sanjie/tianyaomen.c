// sanjie tianyaomen.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG
	
			����������
			����������
			����������

һ����������Ĺ����Ȼû�п����ûʵĴ���������
����������д�Ŵ��������֡�������������
LONG);

  set("exits", ([
  "north" : __DIR__"tianyaolang1",
  "south" : __DIR__"tianyaolu9",
]));
  set("outdoors", 1);

  setup();
}
