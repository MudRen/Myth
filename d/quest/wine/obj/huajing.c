#include <ansi.h>
inherit ITEM;
#include <dbase.h>
#include "flowers.h"
int DEBUG=1;

void setname() 
{ 
//      object ob = this_player();
        int i; 
        string name; 
        i=random(sizeof(flowers)); 
        name=flowers[i]+"花精"; 
        set_name(name, ({"hua jing","jing"}));
} 

void create() 
{
    setname();
    set_weight(100);
    set("unit", "瓶");
    setup();
}

void init() 
{
        object me=this_player();
        object ob=this_object();
    add_action("do_combine","combine");
        call_out ("checking",10,me,ob);  
}

int do_combine(string arg) 
{
      object me=this_player();
        object wan,ob; 
//      int count;
        ob=this_object();
        if (!arg) 
          return notify_fail("你要做什么？\n");
        if (arg!="hua jing")
          return notify_fail("你要做什么？\n");
    message_vision(HIC"$N将花精混合在一起，然后默念咒语，将法力注入到花精中，稍顷，$N的手里多了一颗小小的药丸。\n"NOR,me);
      wan=new("/d/quest/wine/obj/wan");
      wan->move(me);
                    return 1;
}

void checking (object me,object ob)
{
        object env;
        me=this_player();
        ob=this_object();
        env=environment(ob);
        if (env==me)
       {
        destruct(ob);
         remove_call_out ("checking");  
        call_out ("checking",1,me,ob);  
       }
}