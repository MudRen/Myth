//Cracked by Roath
//shulin lin9

inherit ROOM;

void create ()
{
        set ("short", "林心");
        set ("long", @LONG

这是森林的中心,据说这里藏有可怕的树精,这到处是一片白骨
地面偏偏就是照射不到一丝阳光,满地的狼藉令人不禁生畏
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));
        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/shulin/lin8",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/shulin/npc/shuyao":1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
