#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ÆßÐÇº£ÌÄ", ({ "qixing haitang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿Å");
            set("long", "Ò»¿ÅÆßÐÇº£ÌÄ\n");
          }

    setup();
}
