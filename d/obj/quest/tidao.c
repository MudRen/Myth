//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIC"�굶"NOR, ({"ti dao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ר���������ȳ����˵��굶��\n");
                set("unit", "��");
               set("owner_name","���ɮ");
                set("owner_id","tidu seng");
        }
}

