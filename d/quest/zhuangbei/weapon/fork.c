#include <weapon.h>
inherit FORK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("fork");
        set_name(HIB+name["name"]+NOR, name["id"]);       
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
                if(random(20)>10)
                        set("weapon_prop/force",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/parry",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/strength",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_fork(40+random(60));
        if(this_object()->query("inset_hole"))
                str += "一柄锋利的钢叉，装备等级5。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一柄锋利的钢叉，装备等级5。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/force"))
                str += "装备它可增加"+this_object()->query("weapon_prop/force")+"点内功有效等级。\n";
        if(this_object()->query("weapon_prop/parry"))
                str += "装备它可增加"+this_object()->query("weapon_prop/parry")+"点招架。\n";
        if(this_object()->query("weapon_prop/strength")) 
                str += "增加"+this_object()->query("weapon_prop/strength")+"点臂力。\n";
        set("long",str);
        setup();
}

void init()
{
        add_action("do_wield","wield");
}

int do_wield(string arg) 
{  
        object ob = this_object();
        object me = this_player();
        if(arg == ob->query("id") || arg == "fork" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法装备这件兵器。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
