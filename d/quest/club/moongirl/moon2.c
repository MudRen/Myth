//九霄冷月宫
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "坤月宫");
        set ("long", @LONG

你好像走进了一个童话的世界，到处都是那么得可爱，这里
的主人〖暗夜の月〗布娃娃，正在天真的对着你笑呢。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"gong3", 
       "south" : __DIR__"gong2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/wizz/junhyun/usr/buwawa" : 1,
        ]));

        set("indoors", "坤月宫");
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

