#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("������", ({ "yangtui", "tui" }) );
        set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ��������������ȡ�\n");
                set("unit", "ֻ");
                set("value", 100);
                set("food_remaining", 8);
                set("food_supply", 40);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "bone");
        }
        init_hammer(3);
        setup();
}

int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("���ȹ�ͷ", ({ "bone" }) );
        set_weight(150);
        set("long", "һ���еþ�������ȹ�ͷ��\n");
        return 1;
}

