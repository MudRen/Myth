#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"ǧ������"NOR, ({ "qianri zuilan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("long", "һֻǧ������\n");
          }

    setup();
}
