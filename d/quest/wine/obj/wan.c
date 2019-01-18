// wan.c 百花丸 

inherit ITEM;
#include <ansi.h>

void init()
{
          object me = this_object();
         object who = this_player();
         object where = environment();
         if (!wizardp(this_player())) {
                set("no_give", "这样东西不能随便给人。\n");
                set("no_drop", "这么宝贵的东西，哪能随便乱扔。\n");
              set("no_sell", "这样东西不能卖。\n");
              set("no_get","这样东西捡不起来。\n");
              set("no_put","你要干什么？\n");
           }
        if (! me->query("my_owner") && interactive (who))
        me->set("my_owner",who->query("id"));
     if (userp(where))
     {
        if (me->query("owned"))
        {
            if (me->query("owned")!=where->query("id"))
            {call_out("destruct_me",1,where,me);}
        }
        else
        {
           me->set("owned",where->query("id"));
         }
     }
}

void destruct_me(object where, object me)
{
    message_vision("千面怪鬼鬼祟祟地拿起$n撒脚就跑,快追!\n",where,me);
    destruct (me);
}

void create()
{
        set_name(RED"百花丸"NOR, ({"baihua wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒贵重的药丸，不知有什么特殊用处。\n");
                set("value", 5000);
              }
        setup();
}
