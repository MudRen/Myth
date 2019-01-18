// xiaohuandan.c С����
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"С����"NOR, ({ "xiaohuan dan","dan" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","һ����ҩ����ɫ���̡��������������ҩ�������������𣬾������������������Ļָ���\n");
                set("unit", "��");
                set("value", 2000);
                set("drug_type", "��Ʒ");
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
        
        if (arg!="dan" && arg!="xiaohuan dan")
                return 0;
        if (arg!="dan" ) return 0;   
        
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("food",(int)ob->max_food_capacity());
        ob->set("water",(int)ob->max_water_capacity());

        write(HIG+"���ó�һ��С������������У�������ȥ����ʱ��һ��ƮƮ���ɵĸо������ϲ�ʹ��ƣ���ƺ�һ���Ӷ���ʧ�ˡ�\n"NOR);

        message("vision", HIG + ob->name() + "�ó�һ��С������������У�������ȥ����ʱ��һ��ƮƮ����
�ĸо������ϲ�ʹ��ƣ���ƺ�һ���Ӷ���ʧ�ˡ�\n"+NOR,environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "xiaohuan dan" || arg == "dan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
