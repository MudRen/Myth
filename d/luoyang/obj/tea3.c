inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("������", ({"longjing tea", "tea"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ߴִŴ��룬����ʢ���������衣\n");
                set("unit", "��");
                set("value", 4);
        set("max_liquid", 4);
    }
    set("liquid", ([
        "type": "tea",
        "name": "��ˮ",
        "remaining": 4,
        "drunk_supply": 0,
    ]));
}

