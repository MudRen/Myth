
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ����
���ģ�������һ�����֣������и�С����
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xiaodao1",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"shulin5",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
        ]));
	setup();
}
