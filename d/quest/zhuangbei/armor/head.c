// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit HEAD;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("head");
        set_name(HIB+name["name"]+NOR, name["id"]);                 
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("armor_prop/armor", 40);
                if(random(20)>10)
                        set("armor_prop/unarmed",10+random(10));
                if(random(10)>6)
                        add("armor_prop/courage",3);
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/unarmed") && this_object()->query("armor_prop/courage"))
                str += "一顶奇特的帽子,样子并不是很美观，装备等级5。\n"
                +"装备它可增加"+this_object()->query("armor_prop/unarmed")+"点扑击格斗有效等级。\n"
                +"增加"+this_object()->query("armor_prop/courage")+"点胆识。\n";
        else if(this_object()->query("armor_prop/unarmed")) 
                str += "一顶奇特的帽子,样子并不是很美观，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/unarmed")+"点扑击格斗有效等级。\n";
        else if(this_object()->query("armor_prop/courage"))
                str += "一顶奇特的帽子,样子并不是很美观，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/courage")+"点胆识。\n";
        else 
                str += "一顶奇特的帽子,样子并不是很美观，装备等级5。\n";
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
        if(arg == ob->query("id") || arg == "head" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法戴上这顶帽子。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
