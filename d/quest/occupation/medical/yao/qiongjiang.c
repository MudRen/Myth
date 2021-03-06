// qiongjiang.c 雪参冰果琼浆露
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"雪参冰果琼浆露"NOR, ({ "qiongjiang lu","lu" }) );        
        set("weight", 90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "强身健体之饮品。\n");
                set("unit", "滴");
                set("value", 2000);
                set("drug_type", "补品");
        }
        set("is_monitored",1);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drop","drop");
}

int do_drink(string arg)
{
        object ob;        
        ob=this_player();
        
        if (arg!="lu" && arg!="qiongjiang lu")
                return 0;
        if (arg!="lu" ) return 0;
        
        if( living(this_player()) ==0 ) return 0;
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("force", (int)ob->query("max_force")*2);
        ob->set("mana", (int)ob->query("max_mana")*2);
        
        ob->set("food",(int)ob->max_food_capacity());
        ob->set("water",(int)ob->max_water_capacity());
        ob->add("potential",2000);
        
        write(WHT+"你喝下一滴雪参冰果琼浆露，顿觉心清气爽，身上的伤已经痊愈，你的潜能增加了。\n"NOR);

        message("vision", WHT + ob->name() + "喝下一滴雪参冰果琼浆露，顿觉心清气爽，身上的伤已经痊愈。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "qiongjiang lu" || arg == "lu"){
                message_vision("好可惜呀，这么珍贵的药就这样被"+me->query("name")+"随手扔掉了，"+ob->query("name")+"转眼间就消失的无影无踪。\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
