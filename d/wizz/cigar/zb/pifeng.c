
#include <armor.h>
#include <ansi.h>


inherit SURCOAT;


void create()
{
        set_name(HIB"天"+HIM"彩"+HIY"披风"NOR, ({"tiancai pifeng","pifeng","cloth"}) );
        set("long", "据说此件披风是收集了女娲补天剩下的天彩石而缝制成的。\n");
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		
                set("unit", "件");
                set("long","白狐披风。\n");
                set("no_put",1); 
set("value", 15000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
                set("no_give",1);
                set("no_zm",11);
          	set("material", "leather");
                set("armor_prop/armor", 75);
//:                set("armor_prop/dodge", 70);
             }
 		setup();
}

