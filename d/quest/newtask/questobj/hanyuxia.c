#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ĞşÒõº®ÓñÏ»", ({ "hanyu xia" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Ö»");
            set("long", "Ò»Ö»ĞşÒõº®ÓñÏ»\n");
          }

    setup();
}
