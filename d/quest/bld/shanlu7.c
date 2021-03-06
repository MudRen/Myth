//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","山路");
        set ("long", @LONG

一条曲曲折折的小路，向上只通到山上，不过道路陡峭，不太好
走。两边是点点野花，青青小草。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu6",
                "northup" : __DIR__"shandian",
        ]));

        set("item_desc", ([ /* sizeof() == 1 */
                "northup" : "望上隐约看到山颠。\n",
]));

        set("objects", 
        ([ //sizeof() == 2
               __DIR__"npc/erlang" : 1,
               __DIR__"npc/dog" : 1,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   if (dir == "northup" ) {
        if (objectp(present("erlang shen", environment(me))))
   return notify_fail(HIW"二郎神"NOR+"说道：上面乃囚禁三圣母之地，请速速离开！"
+HIW"啸天犬"NOR+"对你叫了几声。\n\n",me);

        }   
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_dian", "dian");
}

int do_dian(string arg)
{       
        object me=this_player();
        object deng;
        object erlang=present("erlang shen", this_object());
        object dog=present("xiaotian quan", this_object());

        if(!(deng=present("baolian deng", me)))
        return notify_fail("你没"+HIY"宝莲灯"NOR+"怎么点？ \n");

        if (arg != "deng"  && arg!= "baolian deng")
        return notify_fail("你要点什么？ \n");

        if ( me->query("bld/done") ==1)
        return notify_fail("你当今天元宵节，没事点灯玩？ \n");

        if (me->query("bld/erlang") != 1  || me->query("bld/dog") !=1)
        return notify_fail("离点灯的时间还早呢？ \n");

       message_vision(HIY"宝莲灯"NOR+"被你的心点燃，放出万道光芒！ \n",me);
       destruct (erlang);
       destruct(dog);
       destruct(deng);
       message_vision(HIW"啸天犬"NOR+"和"HIW"二郎神"NOR+"一下被光照成了灰烬，四散而去！ \n",me);
       message_vision(HIY"宝莲灯"NOR+"也渐渐暗淡，随风化去！ \n",me);
       return 1;
}

