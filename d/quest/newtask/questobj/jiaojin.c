#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name("鲛筋", ({ "jiao jin" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                       set("material", "silk");
 set("long", "用鲨鱼筋焙制而成的绳子，韧力极强，非人力所能扯断。\n");
                  }
           setup();
}
