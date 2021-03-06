// bilingdan.c 碧灵丹
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"碧灵丹"NOR, ({ "biling dan","dan" }) );        
        set("weight", 90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "治伤且能解毒之灵药。\n");
                set("unit", "颗");
                set("value", 2000);
                set("drug_type", "补品");
        }
        set("is_monitored",1);
        setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_drop","drop");
}

int do_eat(string arg)
{
        object ob;
        ob=this_player();
        
        if (arg!="dan" && arg!="biling dan")
                return 0;
        if (arg!="dan" ) return 0;
                
        if( living(this_player()) ==0 ) return 0;
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));       
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("force", (int)ob->query("max_force"));
        ob->set("mana", (int)ob->query("max_mana"));
        
        ob->set("food",(int)ob->max_food_capacity());
        ob->set("water",(int)ob->max_water_capacity());
        if((int)ob->query_condition("hell_zhua"))
                ob->clear_condition("hell_zhua");
        if((int)ob->query_condition("fs_poison"))
                ob->clear_condition("fs_poison");
        
        write(HIY"你吞下一颗碧灵丹，顿觉心清气爽，身上的伤已经痊愈，体内的奇毒也被驱除了。\n"NOR);

        message("vision", HIY + ob->name() + "吞下一颗碧灵丹，顿觉心清气爽，身上的伤已经痊愈，体内的奇毒也被驱除了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "biling dan" || arg == "dan"){
                message_vision("好可惜呀，这么珍贵的药就这样被"+me->query("name")+"随手扔掉了，"+ob->query("name")+"转眼间就消失的无影无踪。\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
