inherit ROOM;


void create()
{
        set("short", "经楼");
        set("long", @LONG
这里是蜀山的经阁，蜀山武功从来口耳相
传，所以并没有什么太多的古籍，几个剑童悠
闲的擦拭着书架
LONG
        );

        set("exits", ([
                "west" : __DIR__"square",
        ]));

        set("objects", ([
                __DIR__"npc/jiantong" : 1,
  "/obj/zhangmen/shushan.c" : 1,
//              __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/yijing" : 1,
        ]));

        setup();
          call_other( "/obj/board/shushans_ss", "???" ); 
/*
        replace_program(ROOM);
               set("outdoors", "xx" ); 
*/
            set("no_clean_up", 0); 
}
