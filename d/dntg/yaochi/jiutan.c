
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��̳", ({"jiu tan", "jiutan", "tan"}));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("max_liquid", 50);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "�ɾ�",
                "remaining": 50,
                "drunk_apply": 5,
        ]));
}
