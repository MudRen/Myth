#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("������", ({"chufei sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѵ���ɫ��ϸ�����������ǳ��Ļ�����\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У�\n");
                set("unwield_msg",
"$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");
        set("weapon_prop/int", 2);

        }
        init_sword(85);
        setup();
}

