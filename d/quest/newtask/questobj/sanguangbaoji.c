#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【三光神功宝籍】", ({ "sanguang baoji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "华山派本门武学秘籍，分上、下两册。上册为三光剑法篇，下册为三光拳法篇和掌法篇。\n");
          }

    setup();
}
