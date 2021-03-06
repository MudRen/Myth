// Room: /d/moon/fengxue/lake.c

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "湖畔");
        set("long", @LONG

    绕过一个山脚，在一片树从旁边眺望湖面，发现这里的湖面要安静得多。听说有
人曾经从这里潜水下去过，还在湖底找到许多的珍宝。

LONG);
  set("no_clean_up", 0);
  set("outdoors","fengxue");
  set("exits",([
    "east" : __DIR__"lake",
]));

        setup();
}
void init()
{
  add_action("do_dive","dive");
  add_action("do_move","push");
}

int do_dive()
{
  object me,paper;
  me = this_player();

  if (( !(paper=present("bishui zhou", me))
                ||(string)paper->query("unit")!="张"))
     return notify_fail("你一个猛子扎到水里．．．\n"+
                  "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

  message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
  me->move(__DIR__"shijie2");
  message_vision("恍恍惚惚地，$N到了水底，却发现这个地方居然没有水。\n",me);
  return 1;
}

int do_move(string arg)
{
   object me = this_player();

   if ((string)arg!="shuzhi")
      return notify_fail("什么？\n");

  if (me->query("str") + me->query("force_factor")<40)
   {
      message_vision("$N使劲推了推树枝，却是一点都推不动！\n",me);
          return 1;
   }
   else   {
      message_vision("$N轻轻地拨开身旁的树枝，却发现一条小路。\n",me);
      me->move(__DIR__"xiaolu");
      message_vision("$N从树丛中钻了过来。\n",me);
   }
   return 1;
}
