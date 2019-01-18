#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("Ç§¶¾¹ç", ({ "qiandu gui" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ö»");
            set("long", "Ò»Ö»Ç§¶¾¹ç\n");
          }

    setup();
}
