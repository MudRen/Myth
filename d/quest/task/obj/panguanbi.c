#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
        set_name("�йٱ�", ({"panguan bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���年д�������õġ�������\n");
                set("unit", "��");
                set("owner_name",HIW"����"NOR);
                 set("owner_id","cui jue");
        }
}

