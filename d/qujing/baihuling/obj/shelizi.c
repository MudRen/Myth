// mon@xyj 10/18/98

inherit COMBINED_ITEM;

void create()
{
        set_name("������", ({"sheli zi","sheli"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һö�����ӣ������е���ɮ�Ĺ�ֳ�з��֡�\n");
                set("unit", "Щ");
                set("base_unit", "ö");
                set("base_weight", 50);
                set("value", 10000);
		set("no_sell",1);
        }
        set_amount(1);
        setup();
}

