inherit ROOM;                                                        

void create ()
{
  set ("short", "¾����" );   

    set("exits", ([ 
               "northeast" : __DIR__"tianjue",
                  ]));
    set("objects", ([ 
               "/d/zhuxian/npc/huoshen" : 1,
                  ]));
    setup();
}
