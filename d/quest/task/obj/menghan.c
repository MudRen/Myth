//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIM "�ɺ�ҩ" NOR, ({"menghan yao", "yao"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ͨ�������õ��ɺ�ҩ��\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","hua ren");
        }
}



