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
       "up" : "/d/milin/qy/u1",   
       "south" : "/d/milin/qy/6",   
       "down" : "/d/milin/qy/d1",   
// 16         "northup" : "/d/migong/migong1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
 call_other("/obj/board/milin_b","???");
        replace_program(ROOM);
}
