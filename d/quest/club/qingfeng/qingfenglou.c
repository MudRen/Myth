inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼");
  set ("long", HIC@LONG
  
                清  风  细  雨  楼

这里是〖清风细雨楼〗的总坛大堂，堂中格调高雅，桌椅整齐干净，
香炉焚出缕缕清香，不禁让人精神一震。平时，清风细雨楼的帮众
都喜欢在这里聚首一堂，闲话家常。许多时候，许多重大会议也在
这里举行。

LONG NOR);

  set("exits",([
  "out" : "/d/city/center",
  "enter" : __DIR__"qingfenglou1",
//   "enter" : __DIR__"woshi",
  ]));
set("objects", ([ /* sizeof() == 1 */
                "/u/cigar/npc/xiaotong" : 1,
                "/u/cigar/npc/xiaotong" : 2,
        ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
