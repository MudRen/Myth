//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIR "·üÄ§µ¶" NOR, ({"fumodao", "fumo"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»°Ñ½µ·þÑýÄ§µÄ±¦µ¶¡£\n");
                set("unit", "°Ñ");
                 set("owner_name","¹¬±ø");
               set("owner_id","gong bing");
        }
}


