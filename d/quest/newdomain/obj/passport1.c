#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"一级通行证"NOR, ({ "passport I","passport" }) );
        set_weight(100);
                set("unit", "张");
                set("material", "paper");
                set("pass_level",1);
                set("long", "这是一张进入奇幻世界的通行证。\n");
        setup();
}
