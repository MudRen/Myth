#include <weapon.h>
inherit BLADE;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("blade");
        set_name(HIB+name["name"]+NOR, name["id"]);                
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5000);
                set("material", "steel");
                set("level_quest",5);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，顿时一股寒气扑面而来！\n");
                set("unwield_msg", "$N将手中的$n插入刀鞘。\n");                
                if(random(20)>10)
                        set("weapon_prop/kee", 200+random(500));
                if(random(10)<2)
                        add("weapon_prop/intelligence",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_blade(40+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "一把寒光闪闪的圆头长刀，刀把上镶嵌有白玉，装备等级5。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一把寒光闪闪的圆头长刀，刀把上镶嵌有白玉，装备等级5。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/kee"))
                str += "装备它可增加"+this_object()->query("weapon_prop/kee")+"点气血。\n";
        if(this_object()->query("weapon_prop/intelligence")) 
                str += "增加"+this_object()->query("weapon_prop/intelligence")+"点悟性。\n";
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
        if(arg == ob->query("id") || arg == "blade" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法装备这件兵器。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
