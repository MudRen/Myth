#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"Ů����"NOR, ({ "nverhong" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ƿ");
            set("long", "һƿŮ����\n");
          }

    setup();
}
