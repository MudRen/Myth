// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ز��ڰ���", ({"subao", "bao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������硢�����ڵ��ز��ڹ������ӡ�\n");
                set("unit", "��");
                set("value", 25);
                set("food_remaining", 1);
                set("food_supply", 60);
        }
}

