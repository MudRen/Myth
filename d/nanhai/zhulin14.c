//Cracked by Roath
// Room: /d/nanhai/zhulin.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ӻ�ɽ�������֡�Ҳ�ǹ������������������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhulin8",
  "west" : __DIR__"zhulin"+sprintf("%d", 6+random(9)),
  "north" : __DIR__"zhulin"+sprintf("%d", 6+random(9)),
  "east" : __DIR__"zhulin"+sprintf("%d", 6+random(9)),
]));

  setup();
  replace_program(ROOM);
}
