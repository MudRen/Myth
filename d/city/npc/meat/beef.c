//Last modified by waiwai@2001/05/03

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ţ��", ({ "beef" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "��! �����ţ��! ���Ի���ʲô?\n");
		set("unit", "��");
		set("value", 1000);
        	set("food_remaining", 3);
		set("food_supply", 80);
        	set("material", "rib");
	}
        setup();
}

int finish_eat()
{
        set_name("ţ�߹�", ({ "rib" }) );
        set_weight(200);
        set("long", "�еþ����ţ�ߡ�\n");
        return 1;
}

	
