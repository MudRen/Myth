#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"���ľ�"NOR, ({ "qingxin jing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("long", "һ�����ľ�\n");
          }

    setup();
}
