//Last modified by waiwai@2001/05/03

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("ţβ", ({ "tail" }) );
        set_weight(200);
	set("long", "һ���ִ��ֳ���ţβ\n");
	set("unit", "��");
	set("value", 1000);
        set("material", "skin");
        set("wield_msg", "$Nץ��һ��$n���������е�������\n");
        init_whip(2);
        setup();
}

