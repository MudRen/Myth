// Room: /u/hkgroup/cave
inherit ROOM;

void create ()
{
  set ("short", "ޤ͡����");
  set ("long", @LONG

����ˮ������к����ʯ��������޵�����������仨������

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"none.c",
  "north" : __DIR__"yard2",
  "south" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");
  
  set("objects", ([
   "/d/obj/misc/seed":1,
  ]));

  setup();
}

/*
int valid_leave(object me, string dir)
{
	if( dir=="up" && !wizardp(me) )
		return notify_fail("¥�����������\n");
	return ::valid_leave(me, dir);
}

*/
