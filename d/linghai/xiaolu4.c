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
  "east" : __DIR__"xiaolu3",
   "west" : __DIR__"wyg",
]));
   set("objects",([
      "/d/wizz/dewbaby/obj/haitang.c":1,
      "/d/wizz/dewbaby/obj/shaoyao.c":1,
  ]));

  setup();
}


