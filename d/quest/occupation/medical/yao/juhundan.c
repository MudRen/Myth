// juhundan.c ��Ԫ�ۻ굤
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"��Ԫ�ۻ굤"NOR, ({ "juhun dan","dan" }) );        
        set("weight", 90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ǿ����֮��ҩ��\n");
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
        
        if (arg!="dan" && arg!="juhun dan")
                return 0;
        if (arg!="dan" ) return 0;
        
        if( living(this_player()) ==0 ) return 0;
        ob->set("kee",2*(int)ob->query("max_kee"));
        ob->set("gin",2*(int)ob->query("max_gin"));
        ob->set("sen",2*(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("force", (int)ob->query("max_force")*2);
        ob->set("mana", (int)ob->query("max_mana")*2);
        
        ob->set("food",2*(int)ob->max_food_capacity());
        ob->set("water",2*(int)ob->max_water_capacity());
        ob->add("combat_exp",2000);
        
        write(HIC+"�����һ����Ԫ�ۻ굤���پ�������ˬ�����ϵ����Ѿ�Ȭ��������ɢ��������������������ѧ�����ˡ�\n"NOR);

        message("vision", HIC + ob->name() + "����һ����Ԫ�ۻ굤���پ�������ˬ�����ϵ����Ѿ�Ȭ��������ɢ���������������\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "juhun dan" || arg == "dan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
