// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "密林");
        set ("long", @LONG
这是一条阴深恐怖的小路,及少有人会来这里,一路上只听见鬼哭声不断.
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/1",   
       "north" : "/d/milin/qy/2",   
       "northwest" : "/d/milin/qy/1",   
       "northeast" : "/d/milin/qy/1",   
       "southeast" : "/d/milin/qy/scc",   
       "southwest" : "/d/milin/qy/2",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
