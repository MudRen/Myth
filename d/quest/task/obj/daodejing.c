//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(YEL"���¾�"NOR, ({"daode book", "book"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������鱾��\n");
                set("unit", "��");
               set("owner_name","��������");
               set("owner_id","faming zhanglao");
        }
}

