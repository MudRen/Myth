// pidudan.c �ٶ���
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"�ٶ���"NOR, ({ "pidu dan","dan" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","һ����ҩ���ɽ��涾��\n");
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
        
        if (arg!="dan" && arg!="pidu dan")
                return 0;
        if (arg!="dan" ) return 0;   

        if((int)ob->query_condition("man_poison"))
                ob->clear_condition("man_poison");
        if((int)ob->query_condition("lvbo_poison"))
                ob->clear_condition("lvbo_poison");
        if((int)ob->query_condition("qzhu_poison"))
                ob->clear_condition("qzhu_poison");
        if((int)ob->query_condition("moon_poison"))
                ob->clear_condition("moon_poison");

        write(CYN+"���ó�һ�űٶ�����������У�������ȥ������Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"NOR);

        message("vision", CYN + ob->name() + 
"�ó�һ�űٶ�����������У�������ȥ������Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "pidu dan" || arg == "dan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
