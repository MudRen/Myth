// r-rose.c 红玫瑰

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(RED "红玫瑰" NOR, ({ "red rose", "rose", "meigui" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", RED "一朵风铃送的红玫瑰，带给你一丝温情。\n" NOR);
                set("value", 5000);
                set("wear_msg", HIM "$N嘻嘻一笑，把花儿别在发髻上，有如天女下凡。\n" NOR);
                set("remove_msg", HIM "$N把花儿从发髻取下，深深闻了闻，揣回怀中。\n" NOR);
                set("armor_prop/armor", 50);
        }
        setup();
}

void init()
{ 
  object ob;
  ob=this_object();
  add_action("come_life","wen");
  add_action("come_life","smell");     
}
        
int come_life(string arg)
{
    object me;
    me=this_player();

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" || arg == "meigui") 
      {
// 41          me->reincarnate();  
        me->set("long", @LONG

                         __  _-==-=_,-.
                        /--`' \_@-@.--<
                       `--'\ \   <___/.
                            \ \\   " /
                              >=\\_/`
                  ____       /= |  \_/|
                _'    `\   _/=== \___/
                 `___/ //\./=/~\====\
                    \   // /   | ===:
                     |  ._/_,__|_ ==:        __
                      \/    \\ \\`--|       / \\
                       |    _     \\:      /==:-\
                       `.__' `-____/       |--|==:
                          \    \ ===\      :==:`-'
                          _>    \ ===\    /==/
                         /==\   |  ===\__/--/
                        <=== \  /  ====\ \\/
                        _`--  \/  === \/--'
                       |       \ ==== |
                        `------/`--' /
                               \___-'

LONG);             
/*
        me->set("env/msg_dest", HIR"【系统】离线指令："HIG"普通百姓 $n(Zen) "HIR"离开游戏了。"NOR);
        me->set("env/msg_home", "【表决】$N投票打开自己的聊天频道。$N的聊天频道被打开了！");
        me->set("env/msg_mout", NOR"$N丢下一万两"HIY"黄金"NOR"。");
        me->set("env/msg_min", NOR"$N捡起一千两"HIY"黄金"NOR"。");
        me->set("env/msg_clone", HIR"【系统】连线精灵："HIG"普通百姓 $n(Zen) "HIR"由 "HIG"255.255.255.255 "HIR"重新连线进入。"NOR);
*/

        message_vision(RED"$N用小指轻轻捻住红玫瑰，拿起来深深地闻了闻。\n"NOR,me);
        tell_object(me, HIY "嗯。。。啊。。。好香呀！\n" NOR);
      }    
    return 1;
}

