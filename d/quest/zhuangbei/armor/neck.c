// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit NECK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("neck");
        set_name(HIB+name["name"]+NOR, name["id"]);                    
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_zm",1);
                set("material", "pearl");
                set("level_quest", 5);
                set("value", 5000);
                set("armor_prop/armor", 60);
                if(random(20)>10)
                        set("armor_prop/force",10+random(10));
                if(random(10)>6)
                        add("armor_prop/personality",3);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/force") && this_object()->query("armor_prop/personality"))
                str += "һ����Ө��������װ���ȼ�5��\n"
                +"װ����������"+this_object()->query("armor_prop/force")+"���ڹ���Ч�ȼ���\n"
                +"����"+this_object()->query("armor_prop/personality")+"����ò��\n";
        else if(this_object()->query("armor_prop/force")) 
                str += "һ����Ө��������װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/force")+"���ڹ���Ч�ȼ���\n";
        else if(this_object()->query("armor_prop/personality"))
                str += "һ����Ө��������װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/personality")+"����ò��\n";
        else 
                str += "һ����Ө��������װ���ȼ�5��\n";
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
        if(arg == ob->query("id") || arg == "neck" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷������⴮������\n");
                        return 1;
                }  
        }   
        return 0;  
}   

