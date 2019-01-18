#include <weapon.h>
inherit BLADE;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("blade");
        set_name(HIY+name["name"]+NOR, name["id"]);              
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱһ�ɺ������������\n");
                set("unwield_msg", "$N�����е�$n���뵶�ʡ�\n");                
                if(random(20)>10)
                add("weapon_prop/kee", 200+random(500));         
                if(random(10)<2)
                        add("weapon_prop/intelligence",3);
                if(random(20)>15)
                add("weapon_prop/sen", 200+random(500));
                if(random(10)>7)
                        add("weapon_prop/attack",10+random(10));
                set("level_quest",50);
        }
        set("inset_hole",2);
        init_blade(100+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "һ�Ѻ���������Բͷ��������������Ƕ�а���װ���ȼ�50��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�Ѻ���������Բͷ��������������Ƕ�а���װ���ȼ�50��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/kee"))
                str += "װ����������"+this_object()->query("weapon_prop/kee")+"����Ѫ��\n";
        if(this_object()->query("weapon_prop/intelligence")) 
                str += "����"+this_object()->query("weapon_prop/intelligence")+"�����ԡ�\n";
        if(this_object()->query("weapon_prop/sen")) 
                str += "����"+this_object()->query("weapon_prop/sen")+"�㾫��\n";
        if(this_object()->query("weapon_prop/attack")) 
                str += "����"+this_object()->query("weapon_prop/attack")+"�����С�\n";
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
                if(me->query("level")<50){
                        write("��ĵȼ��������޷�װ�����������\n");
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
