#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ʮ�����ɢ", ({ "ruanjin san" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ƿ");
            set("long", "һƿʮ�����ɢ\n");
          }

    setup();
}
