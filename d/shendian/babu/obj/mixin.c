#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"����"NOR,({"xiuluo mixin","mixin"}));
    set_weight(100);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "��");
         set("long", "����һ���ɫ������ż���\n");
         set("value", 0);
     }
}
