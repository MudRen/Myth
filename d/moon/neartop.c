//Cracked by Roath
// Room: /moon/neartop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "��Ů��");
  set ("long", @LONG

���￿����Ů�嶥����˵�Ǳ�ѩ��أ��㲢������̫�䡣���ܱ����г���
һЩ��׵�ѩ����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/xuelian" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ontop2.c",
  "eastdown" : __DIR__"yunu5",
  "north" : "/d/quest/m_weapon/lianbianshi",
]));

  setup();
}






