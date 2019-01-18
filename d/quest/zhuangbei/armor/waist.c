// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit WAIST;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("waist");
        set_name(HIB+name["name"]+NOR, name["id"]);                  
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 5000);
                set("material", "metal");
                set("level_quest", 5);
                set("armor_prop/armor", 25);
                if(random(20)>10)
                        set("armor_prop/unarmed",10+random(10));
                if(random(10)>6)
                        add("armor_prop/composure",3);
                set("armor_prop/parry", -10);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/unarmed") && this_object()->query("armor_prop/composure"))
                str += "һֻ�������Ļ��ľ���װ���ȼ�5��\n"
                +"װ����������"+this_object()->query("armor_prop/unarmed")+"���˻�����Ч�ȼ���\n"
                +"����"+this_object()->query("armor_prop/composure")+"�㶨����\n";
        else if(this_object()->query("armor_prop/unarmed")) 
                str += "һֻ�������Ļ��ľ���װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/unarmed")+"���˻�����Ч�ȼ���\n";
        else if(this_object()->query("armor_prop/composure"))
                str += "һֻ�������Ļ��ľ���װ���ȼ�5��\n"
                +"����"+this_object()->query("armor_prop/composure")+"�㶨����\n";
        else 
                str += "һֻ�������Ļ��ľ���װ���ȼ�5��\n";
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
        if(arg == ob->query("id") || arg == "waist" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷�������ֻ���ľ���\n");
                        return 1;
                }  
        }   
        return 0;  
}   

