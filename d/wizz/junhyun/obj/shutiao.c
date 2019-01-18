//ÊíÌõ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Õ¨ÊíÌõ", ({"shu tiao", "shutiao"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ºÐÏãÅçÅçµÄÕ¨ÊíÌõ\n");
                set("unit", "ºÐ");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

