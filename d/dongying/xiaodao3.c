
inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ������ͨ�˴���ּ�С������;�羰��֮���ģ�����������εض�
�����԰ٻ����ޡ��������������������Ǹ�������д�š���ȵ�������
LONG );
	set("exits", ([
		"south" : __DIR__"qingcaop",
		"north" : __DIR__"gate",
                "west" : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
	replace_program(ROOM);
}
