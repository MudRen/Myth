// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
����һ������ֲ���С·,�������˻�������,һ·��ֻ�������������.
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/3",   
       "north" : "/d/milin/qy/4",   
       "west" : "/d/milin/qy/3",   
       "east" : "/d/milin/qy/3",   
       "northeast" : "/d/milin/qy/2",   
       "southwest" : "/d/milin/qy/3",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
