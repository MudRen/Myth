//Last modified by waiwai@2001/05/03

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("牛尾", ({ "tail" }) );
        set_weight(200);
	set("long", "一根又粗又长的牛尾\n");
	set("unit", "根");
	set("value", 1000);
        set("material", "skin");
        set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
        init_whip(2);
        setup();
}

