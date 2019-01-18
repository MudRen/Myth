// jinyuansan.c ��Ԫɢ
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"��Ԫɢ"NOR, ({ "jinyuan san","san" }) );        
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","һСƿ��ҩ���ɽ��涾��\n");
                set("unit", "ƿ");
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
        
        if (arg!="san" && arg!="jinyuan san")
                return 0;
        if (arg!="san" ) return 0;

        if((int)ob->query_condition("hot_poison"))
                ob->clear_condition("hot_poison");
        if((int)ob->query_condition("xx_poison"))
                ob->clear_condition("xx_poison");

        write(HIB+"���ó�һƿ��Ԫɢ��������У�����Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"NOR);

        message("vision", HIB + ob->name() + 
"�ó�һƿ��Ԫɢ��������У�����Ƭ�̣���������涾�ͱ�����ɾ��ˡ�\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "jinyun san" || arg == "san"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
