#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"��˿��"NOR, ({ "hongsijin" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ϯ");
            set("material", "silk");
            set("long", "һϮ��˿��\n");
          }

    setup();
}
