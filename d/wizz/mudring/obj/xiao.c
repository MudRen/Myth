#include <ansi.h>
#include <weapon.h>

inherit F_AUTOLOAD; 
inherit SWORD;

void create()
{
        set_name(HIC"����"NOR,({"dong xiao","xiao"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","֧");
                set("value",1000);
                set("material","blacksteel");
                set("unique", 1);
                set("treasure", 3);       
                set("sharpness", 5);
                set("rigidity", 8);
                set("weapon_prop/parry", 4);
                set("weapon_prop/sword", 4);
                set("wield_neili", 600);
                set("wield_maxneili", 1500);
                set("long","����һ֧���ϵ�"HIG"���"NOR"���ɵ������ʮ�־�����\n");
                set("wield_msg",WHT"$N����͸��һ˿΢Ц,����������ͳ�$n"WHT"�������С�\n"NOR);
                set("unwield_msg",WHT"$N��$n"WHT"�ڿ�������һȦ�����������䡣\n"NOR);
        }

        init_sword(150);
        setup();
}

int query_autoload()
{
return 1;
}

