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
  "south" : __DIR__"zhulin7",
  "west" : __DIR__"zhulin9",
  "north" : __DIR__"zhulin15",
  "east" : __DIR__"zhulin11",
]));

  setup();
  replace_program(ROOM);
}
