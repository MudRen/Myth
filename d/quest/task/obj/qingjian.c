
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIR"���"NOR, ({"qing jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����ϲ�����ר�����\n");
                set("unit", "��");
               set("owner_name","�Ϻ���");
               set("owner_id","xifuhui boss");
        }
}

