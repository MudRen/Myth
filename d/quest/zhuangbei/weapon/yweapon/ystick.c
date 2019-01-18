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
                set("unit", "��");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N��������һ�����һ��$n�������У�\n");
                set("unwield_msg", "$N�������е�$n��\n");                
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
                str += "һ�����ɫ�İ��ӣ������а�����������ͬһ�����߰����ڰ��ϣ�װ���ȼ�50��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�����ɫ�İ��ӣ������а�����������ͬһ�����߰����ڰ��ϣ�װ���ȼ�50��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/spells"))
                str += "װ����������"+this_object()->query("weapon_prop/spells")+"�㷨����Ч�ȼ���\n";
        if(this_object()->query("weapon_prop/dodge")) 
                str += "����"+this_object()->query("weapon_prop/dodge")+"���ܡ�\n";
        if(this_object()->query("weapon_prop/spiritual")) 
                str += "����"+this_object()->query("weapon_prop/spiritual")+"�����ԡ�\n";
        if(this_object()->query("weapon_prop/kee")) 
                str += "����"+this_object()->query("weapon_prop/kee")+"����Ѫ��\n";
        if(this_object()->query("weapon_prop/armor_vs_force")) 
                str += "����"+this_object()->query("weapon_prop/armor_vs_force")+"���ڹ��ֿ�����\n";
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
