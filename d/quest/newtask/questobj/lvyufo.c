#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"�����"NOR, ({ "lvyu fo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("long", "һֻ�����\n");
          }

    setup();
}
