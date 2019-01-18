// xionghuang.c �ۻ���
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"�ۻ���"NOR, ({ "xionghuang wan","wan" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","һ����ҩ���ɽ��߶���\n");
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
        
        if (arg!="wan" && arg!="xionghuang wan")
                return 0;
        if (arg!="wan" ) return 0;

        if((int)ob->query_condition("snake_poison"))
                ob->clear_condition("snake_poison");
        if((int)ob->query_condition("bt_poison"))
                ob->clear_condition("bt_poison");

        write(YEL+"���ó�һ���ۻ��裬������У�������ȥ������Ƭ�̣���������߶��ͱ�����ɾ��ˡ�\n"NOR);

        message("vision", YEL + ob->name() + 
"�ó�һ���ۻ��裬������У�������ȥ������Ƭ�̣���������߶��ͱ�����ɾ��ˡ�\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "xionghuang wan" || arg == "wan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
