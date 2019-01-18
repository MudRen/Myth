#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("staff");
        set_name(HIB+name["name"]+NOR, name["id"]);         
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");                
                if(random(20)>10)
                        set("weapon_prop/sen", 200+random(500));                
                if(random(10)<2)
                        add("weapon_prop/intelligence",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_staff(40+random(60));
        if(random(10)>8)
                add("weapon_prop/damage",this_object()->query("weapon_prop/damage")/4);
        if(this_object()->query("inset_hole"))
                str += "����һ�����صĸ��Ƶ��ȣ�������൱��ʵ��װ���ȼ�5��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "����һ�����صĸ��Ƶ��ȣ�������൱��ʵ��װ���ȼ�5��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/sen"))
                str += "װ����������"+this_object()->query("weapon_prop/sen")+"�㾫��\n";
        if(this_object()->query("weapon_prop/intelligence"))
                str += "װ����������"+this_object()->query("weapon_prop/intelligence")+"�����ԡ�\n";
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
                if(me->query("level")<5){
                        write("��ĵȼ��������޷�װ�����������\n");
                        return 1;
                }  
        }   
        return 0;  
}
