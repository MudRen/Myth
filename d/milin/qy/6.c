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
       "south" : "/d/milin/qy/5",   
       "north" : "/d/milin/qy/6",   
       "west" : "/d/milin/qy/6",   
       "east" : "/d/milin/qy/7",   
       "northeast" : "/d/milin/qy/6",   
       "northwest" : "/d/milin/qy/6",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
