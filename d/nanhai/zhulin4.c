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
  "southwest" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "northwest" : __DIR__"zhulin5",
  "northeast" : __DIR__"zhulin"+sprintf("%d", random(6)),
  "southeast" : __DIR__"zhulin"+sprintf("%d", random(6)),
]));

  setup();
  replace_program(ROOM);
}
