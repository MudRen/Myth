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
                set("long", "�Ĺٳ��Ŀ��⡣\n");
                set("unit", "��");
               set("owner_name","�Ĺ�");
               set("owner_id","wen guan");
        }
}

