// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit HANDS;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("hands");
        set_name(HIY+name["name"]+NOR, name["id"]);                     
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "gold");
                set("value", 10000);
                set("no_zm",1);
                set("armor_prop/armor", 50);
                if(random(20)>10)
                        set("armor_prop/dodge",20+random(20));
                if(random(10)>6)
                        add("armor_prop/composure",3);
                set("level_quest", 50);
        }
        set("inset_hole",2);
        if(this_object()->query("inset_hole"))
                str += "һ�Ի��ƣ�װ���ȼ�50��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�Ի��ƣ�װ���ȼ�50��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("armor_prop/dodge")) 
                str += "����"+this_object()->query("armor_prop/dodge")+"���ܡ�\n";
        if(this_object()->query("armor_prop/composure")) 
                str += "����"+this_object()->query("armor_prop/composure")+"�㶨����\n";
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
        if(arg == ob->query("id") || arg == "hands" ){
                if(me->query("level")<50){
                        write("��ĵȼ��������޷�������Ի��ơ�\n");
                        return 1;
                }  
        }   
        return 0;  
}   

int query_autoload() 
{ 
        object me = this_player();
        if(me->query("level") >= this_object()->query("level_quest"))
        return 1; 
}  

