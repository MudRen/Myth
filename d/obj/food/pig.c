// pig

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����������", ({"zhu rou", "pig"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ĺ��ջ����������⡣\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 60);
        }
}

