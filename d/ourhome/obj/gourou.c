// turou.c ���չ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���չ���", ({"gou rou", "gou", "gourou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ĺ��չ���\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

