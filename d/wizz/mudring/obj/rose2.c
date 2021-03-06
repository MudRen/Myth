// r-rose.c 红玫瑰

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(MAG "紫玫瑰" NOR, ({ "pink rose", "rose", "meigui" }));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", HIR "一朵雪人送的紫玫瑰，带给你一丝温情。\n" NOR);
                set("value", 5000);
                set("wear_msg", HIM "$N嘻嘻一笑，把花儿别在发髻上，有如天女下凡。\n" NOR);
                set("remove_msg", HIM "$N把花儿从发髻取下，深深闻了闻，揣回怀中。\n" NOR);
                set("armor_prop/armor", 50);
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}

void init()
{ 
  add_action("come_life","wen");
  add_action("come_life","smell");
}
        
int come_life(string arg)
{
    object me;
    int i, shen, exp;
    me=this_player();
    shen=me->query("shen");
    exp=me->query("combat_exp");

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" ) 
      {
        if(shen > 0) return 0;
        if((-shen) < exp) return 0;
        i = shen + exp;
        i = -i;        
        i = i/50;
        if(i > 130) i = 130;
        me->set("shen", -(exp));
        me->add("combat_exp", 60+i+random(me->query_skill("poison",1)));
        if(me->query("potential") < me->query("max_pot"))
           me->add("potential", random(i));
        me->reincarnate();        
        message_vision(MAG"$N用小指轻轻捻住紫玫瑰，拿起来深深地闻了闻。\n"NOR,me);
        tell_object(me, HIY "嗯。。。啊。。。好香呀！\n" NOR);
      }
    
    return 1;
}

