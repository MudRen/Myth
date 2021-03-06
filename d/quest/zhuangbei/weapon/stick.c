#include <weapon.h>
inherit STICK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("stick");
        set_name(HIB+name["name"]+NOR, name["id"]);        
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 5000);
                set("material", "iron");
                set("level_quest", 5);
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中！\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
                if(random(20)>10)
                        set("weapon_prop/spells",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/dodge",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/spiritual",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_stick(40+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "一根蓝色的棒子，上面有暗红流动，如同一条火蛇般绕在棒上，装备等级5。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一根蓝色的棒子，上面有暗红流动，如同一条火蛇般绕在棒上，装备等级5。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/spells"))
                str += "装备它可增加"+this_object()->query("weapon_prop/spells")+"点法术有效等级。\n";
        if(this_object()->query("weapon_prop/dodge"))
                str += "装备它可增加"+this_object()->query("weapon_prop/dodge")+"点躲避。\n";
        if(this_object()->query("weapon_prop/spiritual"))
                str += "装备它可增加"+this_object()->query("weapon_prop/spirituale")+"点灵性。\n";
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
        if(arg == ob->query("id") || arg == "stick" ){
                if(me->query("level")<5){
                        write("你的等级不够，无法装备这件兵器。\n");
                        return 1;
                }  
        }   
        return 0;  
}   
