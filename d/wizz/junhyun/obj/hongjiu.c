//���
//junhyun@SK
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�����82", ({"portinas", "hongjiu", "jiu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƿ�Ϻõ�82��ݲ���Ⱥ�ơ�\n");
                set("unit", "ƿ");
                set("value", 50);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "����Ⱥ��",
                "remaining": 15,
                "drunk_apply": 5,
        ]));
}

