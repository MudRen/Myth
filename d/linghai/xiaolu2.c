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
  "east" : __DIR__"xiaolu1",
   "west" : __DIR__"xiaolu3",
]));
   set("objects",([
      "/d/obj/flower/meigui.c":1,
       "/d/obj/flower/guihua.c":2,
  ]));

  setup();
}


