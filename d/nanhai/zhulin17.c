//Cracked by Roath
// Room: /d/nanhai/zhulin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

���Ӻ�ɽ�������֡�Ҳ�ǹ������������������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhulin15",
  "enter" : __DIR__"luohan/luohane1",
]));

	setup();
	replace_program(ROOM);
}
