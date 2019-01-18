//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>

#include <task.h>
void create()
{
        set_name("µ¯Öé", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Å®º¢ÍæµÄµ¯Öé¡£\n");
                set("unit", "¿Ã");
               set("owner_name","Å®º¢");
               set("owner_id","girl");
        }
}

