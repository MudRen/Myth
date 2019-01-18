#include <weapon.h>
inherit HAMMER;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("hammer");
        set_name(HIY+name["name"]+NOR, name["id"]);               
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(21000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");                
                if(random(10)>6)
                        set("weapon_prop/kee", 200+random(500));
                if(random(10)<2)
                        add("weapon_prop/armor_vs_force",10+random(10));
                if(random(20)>15)
                        set("weapon_prop/sen", 200+random(500));        
                set("level_quest",50);
        }
        set("inset_hole",2);
        init_hammer(100+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "����һ�ѳ��ص�������������൱��ʵ��װ���ȼ�50��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "����һ�ѳ��ص�������������൱��ʵ��װ���ȼ�50��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/kee"))
                str += "װ����������"+this_object()->query("weapon_prop/kee")+"����Ѫ��\n";
        if(this_object()->query("weapon_prop/armor_vs_force")) 
                str += "����"+this_object()->query("weapon_prop/armor_vs_force")+"���ڹ��ֿ�����\n";
        if(this_object()->query("weapon_prop/sen")) 
                str += "����"+this_object()->query("weapon_prop/strength")+"�������\n";        
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
        if(arg == ob->query("id") || arg == "hammer" ){
                if(me->query("level")<50){
                        write("��ĵȼ��������޷�װ�����������\n");
                        return 1;
                }  
        }   
        return 0;  
}   

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int diff;
        if( damage_bonus < 0 ) return 0;
        diff = random((int)me->query("force_factor")+1) - random((int)victim->query("force_factor")/2+1);

        if(diff > 0){
                victim->apply_condition("yyz_hurt", 2*(diff + (int)victim->query_condition("yyz_hurt")) );
                message_vision("$Nֻ������һ����������Ȼ���˶���һ��Σ�յĹ�����\n", victim);
        }
        else 
                message_vision("$N����һ����Ϯ�������գ���㱻��������Ҫ����\n", victim);
}

int query_autoload() 
{ 
        object me = this_player();
        if(me->query("level") >= this_object()->query("level_quest"))
        return 1; 
}  
