inherit ROOM;                                                        

void create ()
{
  set ("short", "������" );   

    set("exits", ([ 
               "southwest" : __DIR__"lie",
                  ]));
    set("objects", ([ 
               "/d/zhuxian/npc/leishen" : 1,
                  ]));
    setup();
}
