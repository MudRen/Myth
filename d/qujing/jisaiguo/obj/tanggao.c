inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�Ǹ�", ({ "tanggao"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���Ǹ⣬�����Ѿ����������ˣ������ܳԡ�\n");
                set("unit", "��");
                set("value", 10);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
        setup();
}


