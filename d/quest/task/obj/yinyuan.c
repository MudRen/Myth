//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIW "��Ե��" NOR, ({"yinyuan bo", "book"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ϵ���������Ե���顣\n");
                set("unit", "��");
                set("owner_name","��������");
               set("owner_id","yuexia laoren");
        }
}

