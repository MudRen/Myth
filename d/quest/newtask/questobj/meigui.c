#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"õ�廨"NOR, ({ "meigui hua" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("long", "һֻõ�廨\n");
          }

    setup();
}
