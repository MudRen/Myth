#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIR"�쵤ƿ"NOR, ({"hongdan ping", "ping", "skin"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɫ��С��ƿ�������������صġ�\n");
                set("unit", "��");
		set("no_sell",1);
                set("value", 4000);
                set("max_liquid", 10);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "longgong_hot",
                "name": "�����",
                "remaining": 10,
                "drunk_apply": 5,
        ]));
}

