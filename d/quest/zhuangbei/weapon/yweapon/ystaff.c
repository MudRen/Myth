#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("staff");
        set_name(HIY+name["name"]+NOR, name["id"]);            
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(11500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰后。\n");                
                if(random(20)>10)
                        set("weapon_prop/sen", 200+random(500));                
                if(random(10)<2)
                        add("weapon_prop/intelligence",3);
                if(random(20)>15)
                        set("weapon_prop/force", 10+random(10));
                if(random(10)>7)
                        add("weapon_prop/attack",10+random(10));
                set("level_quest",50);
        }
        set("inset_hole",2);
        init_staff(100+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "这是一根沉重的钢制的杖，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "这是一根沉重的钢制的杖，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/sen"))
                str += "装备它可增加"+this_object()->query("weapon_prop/sen")+"点精神。\n";
        if(this_object()->query("weapon_prop/intelligence")) 
                str += "增加"+this_object()->query("weapon_prop/intelligence")+"点悟性。\n";
        if(this_object()->query("weapon_prop/force")) 
                str += "增加"+this_object()->query("weapon_prop/force")+"点内功有效等级。\n";
        if(this_object()->query("weapon_prop/attack")) 
                str += "增加"+this_object()->query("weapon_prop/attack")+"点命中。\n";
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
        if(arg == ob->query("id") || arg == "staff" ){
                if(me->query("level")<50){
                        write("你的等级不够，无法装备这件兵器。\n");
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
