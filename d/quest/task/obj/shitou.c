//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIG"�Ҳ���ʯͷ", ({"shi tou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ר�������Ҳ�����ʯͷ��\n");
                set("unit", "��");
               set("owner_name","С��å");
                set("owner_id","xiao liumang");
        }
}

