#include <weapon.h>

inherit HAMMER;
inherit F_LIQUID;

void create()
{
        set_name("����Ͳ", ({"qingzhu tong", "tong"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ú�«�Ƴɵ�ˮ����\n");
                set("unit", "��");
                set("max_liquid", 10);
        }
	set("wield_msg", "$Nץ��һ��$n���������е�������\n");
        set("liquid", ([
                "type": "water",
                "name": "�ݵ��Ѿ�û��ζ�Ĳ�ˮ",
                "remaining": 10,
                "drunk_supply": 30,
        ]));
	init_hammer(1);
	setup();
}

