//rubberwood.c 打造武器材料--橡木原木
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name("橡木原木",({"raw rubberwood", "wood"}));
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                 set("no_put",1);
                set("long", "这是一根原木，需要经过加工才能得到有用的木材。\n");
        }
        setup();
}


