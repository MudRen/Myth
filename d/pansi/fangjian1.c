// fangjian1.c
// by lestat/2001.1.31

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Կ���������ǰ������һ������ĵط����������һ��ʯ������ֻ��
��֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·������ϲ���
�������ӣ���Ȼ��һ�ָտ�ʼ�µ��塣
LONG );
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
		    set("objects",([
//                __DIR__"npc/qingxia" : 1,
              "/d/pansi/obj/qin.c":1, 
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
