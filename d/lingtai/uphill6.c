// Room: some place in ��ţ����
// uphill6.c

inherit ROOM;

void create()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

ʯ����ǰ����������ԼԼ�ѿɿ���ɽ�ţ���������������Ȼ������
��Ҳ���ɸ������������Ž���̤̤���Ķ�Ҳ̤̤����������һ����
���ſ�ȥ����������
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"gate",
"southdown": __DIR__"uphill5",
]));
	set("objects", 
	([ //sizeof() == 1
		"/d/xueshan/npc/qingshi-laomo" : 1,
	]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


