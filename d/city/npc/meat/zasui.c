//Last modified by waiwai@2001/05/03

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("йЛтскИ", ({ "fragment" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "©иртЁт╣дтскИ\n");
		set("unit", "╫О");
		set("value", 1000);
       		set("food_remaining", 2);
		set("food_supply", 30);
        	set("material", "blood");
	}

	setup();
}

