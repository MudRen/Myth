inherit ITEM;
inherit F_FOOD;
string *first_name = ({ "��ͷ","ţͷ","��ͷ"});

void create()
{
	string name;
        name = first_name[random(sizeof(first_name))];
	
        set_name(name, ({ "head" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ͷ��\n");
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 8);
                set("food_supply", 100);
        }
}

