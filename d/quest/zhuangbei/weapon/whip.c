#include <weapon.h>
inherit WHIP;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("whip");
        set_name(HIB+name["name"]+NOR, name["id"]);                
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("level_quest", 5);
                set("wield_msg", "$N����һ˦��һ������Ƥ������������\n");
                set("unwield_msg", "$N������$n�������䡣\n");                
                if(random(10)>6)
                        set("weapon_prop/sen", 200+random(500));
                if(random(10)<2)
                        add("weapon_prop/armor_vs_force",10+random(10));
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_whip(40+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "һ�������ı��ӣ�����մ����Ѫ��װ���ȼ�5��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�������ı��ӣ�����մ����Ѫ��װ���ȼ�5��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/sen"))
                str += "װ����������"+this_object()->query("weapon_prop/sen")+"�㾫��\n";
        if(this_object()->query("weapon_prop/armor_vs_force"))
                str += "װ����������"+this_object()->query("weapon_prop/armor_vs_force")+"���ڹ��ֿ�����\n";
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
        if(arg == ob->query("id") || arg == "whip" ){
                if(me->query("level")<5){
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
                victim->apply_condition("lvbo_poison", diff + (int)victim->query_condition("lvbo_poison") );
                message_vision("$Nֻ������һ����������Ȼ���˶���һ��Σ�յĹ�����\n", victim);
        }
        else 
                message_vision("$N����һ����Ϯ�������գ���㱻��������Ҫ����\n", victim);
}
