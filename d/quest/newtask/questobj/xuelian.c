#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"��ɽѩ��"NOR, ({ "tianshan xuelian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("long", "һ����ɽѩ��\n");
          }

    setup();
}
