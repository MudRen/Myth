//�׻ͽ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"���콣"NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 9);
                set("sharpness", 9);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 50);
                set("weapon_prop/parry", 50);
                set("treasure",1);
                set("wield_str", 22);
                set("wield_msg", HIC"
$N��ৡ���һ��������챦����֮��ϼ�����䣬����΢�����������죡\n"NOR);
                set("long", "
����һ���ĳ������ĹŽ�������������������˿˿��⣬��δ���ʣ��ѿɼ��䲻����\n");                
                set("unwield_msg", HIB "���챦������һ��ϼ�⣬��ৡ��ط�����ʡ�\n" NOR);                
        }
         init_sword(195);
        setup();
}

