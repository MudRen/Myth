#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��һ��", ({ "xin yitiao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ƿ");
            set("long", "һƿ��һ��\n");
          }

    setup();
}
