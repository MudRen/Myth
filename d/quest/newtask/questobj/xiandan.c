#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�޼��ɵ�", ({ "wuji xiandan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ö");
            set("long", "һö�޼��ɵ�\n");
          }

    setup();
}
