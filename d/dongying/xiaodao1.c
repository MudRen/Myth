
inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ��������·
�ľ�ͷ�����԰ٻ����ޡ���������������
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiaodao2",
		"west" : __DIR__"nandajie2",
	]));
 	set("objects", ([
	]));
	set("outdoors", 1);
// 	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="east" && (!me->query("family") || me->query("combat_exp") < 1000000))
                return notify_fail("·�м�����һ����С�ơ�������д���������˵ȣ�������롣\n");
        return ::valid_leave(me,dir);
}
