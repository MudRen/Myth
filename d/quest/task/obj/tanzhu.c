//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>

#include <task.h>
void create()
{
        set_name("����", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ů����ĵ��顣\n");
                set("unit", "��");
               set("owner_name","Ů��");
               set("owner_id","girl");
        }
}

