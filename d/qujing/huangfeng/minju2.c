// created by angell 1/1/2001
// room: /d/qujing/huangfeng/minju2.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

�����Ǵ峤�ļң������Ҿ������˴ӳ��������ģ���������
���Ϸ���һ¯�㣬ŨŨ����������������ϴ峤����ÿͣ�
���������������ӭ��������

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 2
		"north" : __DIR__"tulu3",
                "south" : __DIR__"chufang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
         __DIR__"npc/cunzhang" : 1,
         "/d/obj/misc/tables" : 1,
        ]));
      
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
