//Last modified by waiwai@2001/05/03

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
        set_name("ţ��", ({ "hind" }) );
        set_weight(800);
	set("long", "��! �����ţ��! ���Ի���ʲô?\n");
	set("unit", "ֻ");
	set("value", 1000);
        set("food_remaining", 5);
	set("food_supply", 80);
        set("material", "rib");
        set("wield_msg", "$Nץ��һֻ$n���������е�������\n");
        init_hammer(5);
        setup();
}

int finish_eat()
{
        set_name("ţ�ȹ�", ({ "rib" }) );
        set_weight(300);
        set("long", "�еþ����ţ�ȡ�\n");
        return 1;
}

	
