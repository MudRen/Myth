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
        name=flowers[i]+"����"; 
        set_name(name, ({"hua jing","jing"}));
} 

void create() 
{
    setname();
    set_weight(100);
    set("unit", "ƿ");
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
          return notify_fail("��Ҫ��ʲô��\n");
        if (arg!="hua jing")
          return notify_fail("��Ҫ��ʲô��\n");
    message_vision(HIC"$N�����������һ��Ȼ��Ĭ�����������ע�뵽�����У����꣬$N���������һ��СС��ҩ�衣\n"NOR,me);
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