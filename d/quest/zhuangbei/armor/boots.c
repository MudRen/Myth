// Created by kuku@sjsh 2003.3

#include <armor.h>
inherit BOOTS;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("boots");
        set_name(HIB+name["name"]+NOR, name["id"]);                           
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 5000); 
                set("material", "boots");
                set("level_quest", 5);
                set("armor_prop/armor", 30);
                if(random(20)>10)
                        set("armor_prop/spells",10+random(10));
                if(random(10)>6)
                        set("armor_prop/defense",10+random(10));
                set("inset_hole",1);
                set("level_quest",5); 
        }
        if(this_object()->query("armor_prop/spells") && this_object()->query("armor_prop/defense"))
                str += "这是一双晚霞织就的羽绒飞靴，装备等级5。\n"
                +"装备它可增加"+this_object()->query("armor_prop/spells")+"点法术有效等级。\n"
                +"增加"+this_object()->query("armor_prop/defense")+"点防御。\n";
        else if(this_object()->query("armor_prop/spells")) 
                str += "这是一双晚霞织就的羽绒飞靴，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/spells")+"点法术有效等级。\n";
        else if(this_object()->query("armor_prop/defense"))
                str += "这是一双晚霞织就的羽绒飞靴，装备等级5。\n"
                +"增加"+this_object()->query("armor_prop/defense")+"点防御。\n";
        else 
                str += "这是一双晚霞织就的羽绒飞靴，装备等级5。\n";
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
        if(arg == ob->query("id") || arg == "boots" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法穿上这双靴子。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
