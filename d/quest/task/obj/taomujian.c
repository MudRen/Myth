//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIY"ÌÒÄ¾½£"NOR, ({"taomu jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " Í¸×Åº®¹âµÄ±¦½£¡£\n");
                set("unit", "±ú");
                 set("owner_name","Ô¬Ììî¸");
               set("owner_id","yuan tiangang");
        }
}

