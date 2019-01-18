#include <weapon.h>
inherit FORK;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("fork");
        set_name(HIB+name["name"]+NOR, name["id"]);       
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
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
                set("unwield_msg", "$N�������е�$n��\n");                
                if(random(20)>10)
                        set("weapon_prop/force",10+random(10));
                if(random(10)>6)
                        add("weapon_prop/parry",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/strength",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_fork(40+random(60));
        if(this_object()->query("inset_hole"))
                str += "һ�������ĸֲ棬װ���ȼ�5��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�������ĸֲ棬װ���ȼ�5��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/force"))
                str += "װ����������"+this_object()->query("weapon_prop/force")+"���ڹ���Ч�ȼ���\n";
        if(this_object()->query("weapon_prop/parry"))
                str += "װ����������"+this_object()->query("weapon_prop/parry")+"���мܡ�\n";
        if(this_object()->query("weapon_prop/strength")) 
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
        if(arg == ob->query("id") || arg == "fork" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷�װ�����������\n");
                        return 1;
                }  
        }   
        return 0;  
}   
