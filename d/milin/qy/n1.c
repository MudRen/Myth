// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "С·");
        set ("long", @LONG
����һ������ֲ���С·,�������˻�������,һ·��ֻ�������������.

LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/calvin/lanling/jie1",   
       "north" : "/d/milin/qy/men.c",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
