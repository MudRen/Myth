//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
        set_name("’–≈∆", ({"zhao pai", "pai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“©∆Ã’∆πÒ—Ó÷–À≥µƒ¿œ◊÷∫≈’–≈∆°£\n");
                set("unit", "øÈ");
                 set("owner_name","—Ó÷–À≥");
               set("owner_id","yang zhongshun");
        }
}

