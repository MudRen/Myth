// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit NECK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("neck");
        set_name(HIY+name["name"]+NOR, name["id"]);                     
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("no_zm",1);
                set("material", "pearl");
                set("value", 10000);
                set("armor_prop/armor", 80);
                if(random(20)>10)
                        set("armor_prop/force",20+random(20));
                if(random(10)>6)
                        add("armor_prop/personality",3);
                set("level_quest", 50);
        }
        set("inset_hole",2);
        if(this_object()->query("inset_hole"))
                str += "一串晶莹剔透的项链，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一串晶莹剔透的项链，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("armor_prop/force")) 
                str += "增加"+this_object()->query("armor_prop/force")+"点内功有效等级。\n";
        if(this_object()->query("armor_prop/personality")) 
                str += "增加"+this_object()->query("armor_prop/personality")+"点容貌。\n";
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
                if(me->query("level")<50){
                        write("你的等级不够，无法戴上这串项链。\n");
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

