inherit ITEM;
inherit F_FOOD;

void create()
{
        int i;
        string *names = ({ "ʯ����", "������", "����" });
        i = random(3);
        set_name(names[i], ({ "fish" }) );
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ոյ����������㡣\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}



