#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(RED"õ���㾫"NOR,({"meigui xiangjing","xiangjing"}));
    set_weight(1000);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "��");
         set("long", "����һ��õ���㾫��\n");
         set("value", 20000);
     }
}
