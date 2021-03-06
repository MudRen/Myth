#include <weapon.h>
inherit STICK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("stick");
        set_name(HIY+name["name"]+NOR, name["id"]);        
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中！\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
                if(random(20)>10)
                        set("weapon_prop/spells",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/dodge",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/spiritual",3);
                if(random(20)>15)
                        set("weapon_prop/kee", 200+random(500));
                if(random(10)>7)
                        add("weapon_prop/armor_vs_force",10+random(10));
                set("level_quest",50);
        }
        set("inset_hole",2);
        init_stick(100+random(60));
        if(this_object()->query("inset_hole"))
                str += "一根金黄色的棒子，上面有暗红流动，如同一条火蛇般绕在棒上，装备等级50。\n"+"它身上有"+this_object()->query("inset_hole")+"个可镶嵌宝石的孔。\n"; 
        else
                str += "一根金黄色的棒子，上面有暗红流动，如同一条火蛇般绕在棒上，装备等级50。\n"+"它身上没有可镶嵌宝石的孔。\n"; 
        if(this_object()->query("weapon_prop/spells"))
                str += "装备它可增加"+this_object()->query("weapon_prop/spells")+"点法术有效等级。\n";
        if(this_object()->query("weapon_prop/dodge")) 
                str += "增加"+this_object()->query("weapon_prop/dodge")+"点躲避。\n";
        if(this_object()->query("weapon_prop/spiritual")) 
                str += "增加"+this_object()->query("weapon_prop/spiritual")+"点灵性。\n";
        if(this_object()->query("weapon_prop/kee")) 
                str += "增加"+this_object()->query("weapon_prop/kee")+"点气血。\n";
        if(this_object()->query("weapon_prop/armor_vs_force")) 
                str += "增加"+this_object()->query("weapon_prop/armor_vs_force")+"点内功抵抗力。\n";
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
