#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����л�ɢ", ({ "juhunsan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ƿ");
            set("long", "һƿ����л�ɢ\n");
          }

    setup();
}
