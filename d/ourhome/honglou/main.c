// Room: /u/hkgroup/main
inherit ROOM;

void create ()
{
  set ("short", "���¥");
  set ("long", @LONG

�������Ρ�룬��¥���������չ��ϱ��������������С�
���ɷ��ܣ�����������������棬�ʻ��ͷ��

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"fairyplace",
  "west" : __DIR__"mainwest",
  "north" : __DIR__"bridge",
  "south" : __DIR__"yard2",
  "east" : __DIR__"maineast",
]));
  set("objects", ([ /* sizeof() == 1 */
"/obj/boss/honglou_leng" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
  "obj/board/honglou_b"->foo();
}
