#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��Ϲƶ�", ({ "jincan gudu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Щ");
            set("long", "һЩ��Ϲƶ�\n");
          }

    setup();
}
