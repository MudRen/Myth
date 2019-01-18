#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
        set_name("ÅÐ¹Ù±Ê", ({"panguan bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "´Þçå¹´Ð´ÉúËÀ±¡ÓÃµÄ¡£¡£¡£¡£\n");
                set("unit", "¸ö");
                set("owner_name",HIW"´Þçå"NOR);
                 set("owner_id","cui jue");
        }
}

