#include <weapon.h>
inherit SPEAR;
#include <ansi.h>

void setname() 
{ 
        mapping name;
        name=__DIR__"name"->random_name("spear");
        set_name(HIB+name["name"]+NOR, name["id"]);          
} 

void create()
{
        string str = "";
        setname(); 
        set_weight(5500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
                set("level_quest", 5);
                set("wield_msg", "$N����$n�������У��������ݡ�\n");
                set("unwield_msg", "$N����һ��ǹ����������֮������������\n");                
                if(random(20)>10)
                        set("weapon_prop/kee",200+random(500));
                if(random(10)>6)
                        add("weapon_prop/dodge",10+random(10));
                if(random(10)<2)
                        add("weapon_prop/spiritual",3);
                set("level_quest",5); 
        }
        set("inset_hole",1);
        init_spear(40+random(60));
        if(this_object()->query("inset_hole"))
                str += "һ�˾��ִ��Ƶ�ǹ��װ���ȼ�5��\n"+"��������"+this_object()->query("inset_hole")+"������Ƕ��ʯ�Ŀס�\n"; 
        else
                str += "һ�˾��ִ��Ƶ�ǹ��װ���ȼ�5��\n"+"������û�п���Ƕ��ʯ�Ŀס�\n"; 
        if(this_object()->query("weapon_prop/kee"))
                str += "װ����������"+this_object()->query("weapon_prop/kee")+"����Ѫ��\n";
        if(this_object()->query("weapon_prop/dodge"))
                str += "װ����������"+this_object()->query("weapon_prop/dodge")+"���ܡ�\n";
        if(this_object()->query("weapon_prop/spiritual"))
                str += "װ����������"+this_object()->query("weapon_prop/spiritual")+"�����ԡ�\n";
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
        if(arg == ob->query("id") || arg == "spear" ){
                if(me->query("level")<5){
                        write("��ĵȼ��������޷�װ�����������\n");
                        return 1;
                }  
        }   
        return 0;  
}
