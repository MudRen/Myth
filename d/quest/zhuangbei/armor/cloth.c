// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("cloth");
        set_name(HIB+name["name"]+NOR, name["id"]);                              
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("material", "cloth");
                set("unit", "��");
                set("level_quest", 5);
                set("value", 5000);
                set("armor_prop/armor", 90);
                if(random(20)>10)                       
                        set("armor_prop/dodge", 20+random(20)); 
                if(random(10)>6)
                        add("armor_prop/karma",3);
                set("armor_prop/parry", -20);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/dodge") && this_object()->query("armor_prop/karma"))
                str += "һ���������ۣ�װ���ȼ�5��\n"
                +"װ����������"+this_object()->query("armor_prop/dodge")+"���ܡ�\n"
                +"����"+this_object()->query("armor_prop/karma")+"�㸣Ե��\n";
        else if(this_object()->query("armor_prop/dodge")) 
                str += "һ���������ۣ�װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/dodge")+"���ܡ�\n";
        else if(this_object()->query("armor_prop/karma"))
                str += "һ���������ۣ�װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/karma")+"�㸣Ե��\n";
        else 
                str += "һ���������ۣ�װ���ȼ�5��\n";
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
        if(arg == ob->query("id") || arg == "cloth" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷���������·���\n");
                        return 1;
                }  
        }   
        return 0;  
}   

