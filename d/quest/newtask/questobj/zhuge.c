#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���", ({ "zhu ge" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("material", "bamboo");
            set("long", "һֻ���\n");
          }

    setup();
}
