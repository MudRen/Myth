#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����", ({ "yishen dan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ö");
            set("long", "һö����\n");
          }

    setup();
}
