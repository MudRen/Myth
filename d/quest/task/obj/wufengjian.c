//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>

#include <task.h>
void create()
{
        set_name(HIW"�ڷ��"NOR, ({"wufeng jian", "jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���湫����ϲ�������Ρ�\n");
                set("unit", "��");
               set("owner_name","���湫��");
               set("owner_id","yumian gongzhu");
        }
}

