//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIC"����"NOR, ({"kaoti", "ti"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��֪�³��Ŀ��⡣\n");
                set("unit", "��");
               set("owner_name","��֪��");
               set("owner_id","he zhizhang");
        }
}
