#include <armor.h>
inherit SHIELD;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("shield");
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
                set("unit", "件");
                set("value", 10000);
                set("no_zm",1);
                set("material", "skin");
                set("armor_prop/armor", 170 );
                if(random(20)>10)
                        set("armor_prop/parry",20+random(20));
                if(random(10)>6)
                        set("armor_prop/defense",20+random(20));
                set("armor_prop/dodge", -20);
                set("level_quest", 50);
        }
        set("inset_hole",2);
        if(this_object()->query("inset_hole"))
                str += "一件沉重的盾牌，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一件沉重的盾牌，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("armor_prop/parry")) 
                str += "增加"+this_object()->query("armor_prop/parry")+"点招架。\n";
        if(this_object()->query("armor_prop/defense")) 
                str += "增加"+this_object()->query("armor_prop/defense")+"点防御。\n";
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
        if(arg == ob->query("id") || arg == "shield" ){
                if(me->query("level")<50){
                        write("你的等级不够，无法拿上这件盾牌。\n");
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

