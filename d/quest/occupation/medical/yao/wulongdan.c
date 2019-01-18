// wulongdan.c ������
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLU"������"NOR, ({ "wulong dan","dan" }) );        
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
        
        if (arg!="dan" && arg!="wulong dan")
                return 0;
        if (arg!="dan" ) return 0;

        if((int)ob->query_condition("cold_poison"))
                ob->clear_condition("cold_poison");
        if((int)ob->query_condition("hb_poison"))
                ob->clear_condition("hb_poison");
        if((int)ob->query_condition("yyz_hurt"))
                ob->clear_condition("yyz_hurt");
        if((int)ob->query_condition("scorpion_poison"))
                ob->clear_condition("scorpion_poison");

        write(BLU+"���ó�һ����������������У�������ȥ������Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"NOR);

        message("vision", BLU + ob->name() + 
"�ó�һ����������������У�������ȥ������Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "wulong dan" || arg == "dan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
