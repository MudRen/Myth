//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name("����", ({"qin xian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ҡ�\n");
                set("unit", "��");
                set("owner_name","Ϸ��");
                set("owner_id","xi zi");
        }
}

