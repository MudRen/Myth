// chicken_leg.c
inherit ITEM; 

//#include <weapon.h>

//inherit UNARMED;
inherit F_FOOD;

void create()
{
        set_name("һ������", ({"dami"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"һ�����ף����������ģ�\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 100);
                set("food_supply", 5);
                set("wield_msg", "$Nץ��һ�����ף�����Ҫ����ƴ����\n");
		set("eat_msg",
"$N�ó��������׷ŵ�������˽���������������\n");
                set("material", "bone");
        }
//        init_unarmed(5);
}


