// created by angell 1/1/2001
// room: /d/qujing/huangfeng/wuqidian.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

����ɽ��С�꣬����������ȴ��ʵ��ȫ������������˶�
Ը����������һЩ���ֵļһ�������ϰ���æ�Ű�����
��������װ��ֿ⡣�������ֻ���к�һ������û�з���
���еĻ

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ 
                "east" : __DIR__"tulu4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/wangshan" : 1,
        ]));

	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
