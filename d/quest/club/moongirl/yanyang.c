

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", HIW"天外神天"NOR);
  set ("long", @LONG


★ *     .     *             ☆  ★ *     .    
这里是火舞の艳阳的避世之所
   ☆.         *          ☆             ★
无尽的忧伤，觉得好累好倦.........
           不想再流浪，不愿再彷徨.......☆
                 *                        *         
是啊，该找个归宿了，可是归宿在哪里呢？
                惟有继续流浪继续寻找......
          ★                             ★




LONG);

  set("exits", ([
           "west" : __DIR__"tian1",
//           "east" : __DIR__"yanyang",
      ]));

  set("objects", ([
           "/d/wizz/junhyun/usr/yanyang.c" : 1,
      ]));

  setup();
}
