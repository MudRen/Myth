// created by angell 1/1/2001
// room: /d/qujing/huangfeng/minju1.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

ƽ���Ĵ����˼ң���ֻһ��һ�Σ�ȴ��ʰ�øɾ����ࡣ����
�Ĵ����Ƕ���ȥ�����ˣ�ֻ�м���С�����ڼ��С�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"tulu2",
        ]));

        set("objects", 
        ([ //sizeof() == 3
		__DIR__"npc/boykid" : 1,
		__DIR__"npc/girlkid" : 1,
		]));

	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
