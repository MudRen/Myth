#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����֮��", ({ "jile xing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("long", "һ�ż���֮��\n");
          }

    setup();
}
