//������

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���ͳ������ްԺ���", ({"han bao", "hanbao", "juwuba"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������������ͳ������ްԺ���\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

