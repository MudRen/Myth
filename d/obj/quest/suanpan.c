//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
        set_name(HIG"����"NOR, ({"suan pan", "pan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������õ��������̡�\n");
                set("unit", "��");
               set("owner_name","������");
               set("owner_id","tie suanpan");
        }
}
