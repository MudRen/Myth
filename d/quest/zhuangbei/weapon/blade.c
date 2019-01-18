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
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("level_quest",5);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱһ�ɺ������������\n");
                set("unwield_msg", "$N�����е�$n���뵶�ʡ�\n");                
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
                str += "һ�Ѻ���������Բͷ��������������Ƕ�а���װ���ȼ�5��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�Ѻ���������Բͷ��������������Ƕ�а���װ���ȼ�5��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/kee"))
                str += "װ����������"+this_object()->query("weapon_prop/kee")+"����Ѫ��\n";
        if(this_object()->query("weapon_prop/intelligence")) 
                str += "����"+this_object()->query("weapon_prop/intelligence")+"�����ԡ�\n";
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
                        write("��ĵȼ��������޷�װ�����������\n");
                        return 1;
                }  
        }   
        return 0;  
}   
