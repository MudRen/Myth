
inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
        set_name(HIB"ī��"NOR, ({"mo jing"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ר��ī����\n");
                set("unit", "��");
               set("owner_name","����");
                set("owner_id","yan shu");
        }
}


