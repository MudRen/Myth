// Created by kuku@sjsh 2003.2

#include <armor.h>
inherit WRISTS;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("wrists");
        set_name(HIB+name["name"]+NOR, name["id"]);                               
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 5000); 
                set("material", "metal");
                set("level_quest", 5);
                set("armor_prop/armor", 40);
                if(random(20)>10)
                        set("armor_prop/force",20+random(10));
                if(random(10)>6)
                        add("armor_prop/courage",3);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/force") && this_object()->query("armor_prop/courage"))
                str += "一对护腕，装备等级5。\n"
                +"装备它可增加"+this_object()->query("armor_prop/force")+"点内功有效等级。\n"
                +"增加"+this_object()->query("armor_prop/courage")+"点胆识。\n";
        else if(this_object()->query("armor_prop/force")) 
                str += "一对护腕，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/force")+"点内功有效等级。\n";
        else if(this_object()->query("armor_prop/courage"))
                str += "一对护腕，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/courage")+"点胆识。\n";
        else 
                str += "一对护腕，装备等级5。\n";
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
        if(arg == ob->query("id") || arg == "wrists" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法戴上这对护腕。\n");
                        return 1;
                }  
        }   
        return 0;  
}   

