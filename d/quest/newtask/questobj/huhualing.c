#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������", ({ "huhua" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "steel");
            set("long", "һ��С����\n");
          }

    setup();
}
