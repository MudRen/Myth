//by dewbaby
//xiaolu1

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

�滨�����С·�������Ʈҡ��Ѥ��ʢ����ģ������
���������������ģ��˴����������䡣
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hudi4",
   "west" : __DIR__"xiaolu2",
]));
   set("objects",([
      "/d/obj/flower/juhua.c":1,
      "/d/obj/flower/rose.c":1,
  ]));

  setup();
}


