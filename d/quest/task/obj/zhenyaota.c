//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIW"������"NOR, ({"zhenyao ta", "ta"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "�����׽���ı�����\n");
               set("unit", "��");
               set("owner_name","�");
               set("owner_id","li jing");
        }
}

