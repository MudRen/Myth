// pig

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ͷ��", ({"pig head", "pighead", "head"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�̷���������ͷ�⣬��Ȼ�չ���¯��\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 40);
		set("eat_msg","$Nץ��һ���$n�ͽ����\n");
        }
}

