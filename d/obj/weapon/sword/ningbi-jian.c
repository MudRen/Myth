// sgzl

#include <weapon.h>

//inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name("���̽�", ({"ningbi sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѵ���ɫ��ϸ����������͸�������洦���ŵ�㺮�⣬�ƺ�ι�˾綾��\n");
                set("orilong","һ�ѵ���ɫ��ϸ����������͸�������洦���ŵ�㺮�⣬�ƺ�ι�˾綾��\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��Цһ�����ӱ���γ���$n��\n");
                set("unwield_msg", "$N�����е�$n������У���Ƕ���һ˿Ц�⡣\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 20);
                set("anqi/now", 0);

        }
        init_sword(60);
        setup();
}

