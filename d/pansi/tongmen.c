// tongmen.c
// by lestat

inherit ROOM;

void create()
{
	set("short", "�׹Ƕ�");
	set("long", @LONG
����һ�����ε�ͭ�ţ����Եı������š��׹Ƕ����������֡�
LONG );
	set("exits", ([
		"south" : __DIR__"shiji3",
		"west" : __DIR__"fangjian3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
