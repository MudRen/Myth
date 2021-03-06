// xionghuang.c 雄黄丸
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"雄黄丸"NOR, ({ "xionghuang wan","wan" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","一颗灵药，可解蛇毒。\n");
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
        
        if (arg!="wan" && arg!="xionghuang wan")
                return 0;
        if (arg!="wan" ) return 0;

        if((int)ob->query_condition("snake_poison"))
                ob->clear_condition("snake_poison");
        if((int)ob->query_condition("bt_poison"))
                ob->clear_condition("bt_poison");

        write(YEL+"你拿出一颗雄黄丸，放入口中，吞了下去，不消片刻，身体里的蛇毒就被祛除干净了。\n"NOR);

        message("vision", YEL + ob->name() + 
"拿出一颗雄黄丸，放入口中，吞了下去，不消片刻，身体里的蛇毒就被祛除干净了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "xionghuang wan" || arg == "wan"){
                message_vision("好可惜呀，这么珍贵的药就这样被"+me->query("name")+"随手扔掉了，"+ob->query("name")+"转眼间就消失的无影无踪。\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
