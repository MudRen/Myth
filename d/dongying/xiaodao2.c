

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ��������·
�ľ�ͷ�����԰ٻ����ޡ����������������ϱߺ�������ζɢ��������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiaodao1",
		"east" : __DIR__"xiaodao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
	replace_program(ROOM);
}
