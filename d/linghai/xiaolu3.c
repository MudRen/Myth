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
  "east": __DIR__"xiaolu2",
    "west" : __DIR__"xiaolu4",
]));
   set("objects",([
      "/d/wizz/dewbaby/obj/lilac.c":1,
  ]));

  setup();
}


