// xiongdan.c �����ܵ���
// Created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�����ܵ���"NOR, ({ "xiongdan wan","wan" }) );        
        set("weight", 90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩ��\n");
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
        
        if (arg!="wan" && arg!="xiongdan wan")
                return 0;
        if (arg!="wan" ) return 0;   
        
        if( living(this_player()) ==0 ) return 0;
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));       
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));
        
        ob->set("food",(int)ob->max_food_capacity());
        ob->set("water",(int)ob->max_water_capacity());

        write(HIW+"������һ�Ű����ܵ��裬����Ƭ�̣����ϵ��˾�Ȭ���ˡ�\n"NOR);

        message("vision", HIW + ob->name() + "���°����ܵ��裬��ʱ����һˬ��\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "xiongdan wan" || arg == "wan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
