                 // wine.c ���׾�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���׾�", ({"mijiu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�Ϸ��˰��ԵĽ��׾ơ�\n");
                set("unit", "��");
                set("value", 1200);
		set("food_remaining",120);
                set("food_supply", 120);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "���׾�",
                "drunk_apply": 10,
        ]));
}
