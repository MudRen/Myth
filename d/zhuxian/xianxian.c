inherit ROOM;                                                        

void create ()
{
  set ("short", "������" );   

    set("exits", ([ 
               "northwest" : __DIR__"hongshui",
                  ]));
    set("objects", ([ 
               "/d/zhuxian/npc/fengshen" : 1,
                  ]));
    setup();
}
