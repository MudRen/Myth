//Cracked by Roath
// Room: /moon/yunu1.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����Ҷ��");
  set ("long", @LONG
���ܻ���������֦Ҷ��ï��ȴ�ѿ������ء�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"ontop.c",
  "down" : __DIR__"tree1.c",
]));
	 set("objects", (["/d/obj/flower/guihua.c":2,]));

  setup();
}






