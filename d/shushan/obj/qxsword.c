//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���ǽ�", ({"qixing sword", "sword"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѵ������ǵĽ����������ǳ��Ļ�����\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("sheenness", 35);
                set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У�\n");
                set("unwield_msg",
"$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");

        }
        init_sword(120);
        setup();
}
