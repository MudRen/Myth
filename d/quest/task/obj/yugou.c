//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(CYN"�㹳"NOR, ({"yu gou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " ��������İ�֮�\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","fisher");
        }
}

