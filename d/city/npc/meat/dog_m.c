//Last modified by waiwai@2001/05/03

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "dog" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "��! ����Ĺ���! ���Ի���ʲô?\n");
		set("unit", "��");
		set("value", 1000);
        	set("food_remaining", 3);
		set("food_supply", 60);
        	set("material", "rib");
	}

        setup();
}

int finish_eat()
{
        set_name("����ͷ", ({ "rib" }) );
        set_weight(250);
        set("long", "�еþ���Ĺ���ͷ��\n");
        return 1;
}

	
