inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�����", ({"gaiwan tea", "tea"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ߴִŴ��룬����ʢ���˲�ˮ��\n");
                set("unit", "��");
                set("value", 2);
        set("max_liquid", 4);
    }
    set("liquid", ([
        "type": "tea",
        "name": "��ˮ",
        "remaining": 4,
        "drunk_supply": 0,
    ]));
}

