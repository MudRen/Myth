// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit ARMOR;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("armor");
        set_name(HIB+name["name"]+NOR, name["id"]);                                  
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("level_quest", 5);
                set("value", 5000); 
                set("armor_prop/armor", 80);
                if(random(20)>10)
                        set("armor_prop/force",20+random(10));
                if(random(10)>6)
                        set("armor_prop/attack",10+random(10));
                set("armor_prop/dodge", -10);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/force") && this_object()->query("armor_prop/attack"))
                str += "һ������,�˼�ͨ�巺�����⣬װ���ȼ�5��\n"
                +"װ����������"+this_object()->query("armor_prop/force")+"���ڹ���Ч�ȼ���\n"
                +"����"+this_object()->query("armor_prop/attack")+"�����С�\n";
        else if(this_object()->query("armor_prop/attack")) 
                str += "һ������,�˼�ͨ�巺�����⣬װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/attack")+"�����С�\n";
        else if(this_object()->query("armor_prop/force"))
                str += "һ������,�˼�ͨ�巺�����⣬װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/force")+"���ڹ���Ч�ȼ���\n";
        else 
                str += "һ������,�˼�ͨ�巺�����⣬װ���ȼ�5��\n";
        set("long",str);
        setup();
}

void init()
{
        add_action("do_wear","wear");
}

int do_wear(string arg) 
{  
        object ob = this_object();
        object me = this_player();
        if(arg == ob->query("id") || arg == "armor" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷�����������ס�\n");
                        return 1;
                }  
        }   
        return 0;  
}   
