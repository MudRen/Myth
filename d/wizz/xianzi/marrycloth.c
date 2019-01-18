// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"百合丝衣"NOR, ({"baihe siyi", "siyi", "cloth" }) );
        set("long", "一件珍珠般光滑的丝衣上绣满了盛开的"HIW"百合花。\n"NOR);
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
                set("no_drop",1);
                set("no_give",1);
                set("no_get",1);
                set("no_sell",1);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                      set("wear_msg","$N收集着天边的"HIM"云霞"NOR"，飞燕的"HIW"轻羽"NOR"，织成一件华服披在身上。 映衬着她身似柳烟随风摆，面如梨花带露娇。．\n"); 
                      set("unequip_msg", "$N身上的丝衣突然化成云烟散去，消失在天的尽头。 只在云霞深处留下了轻轻的一抹"MAG"紫雾。\n"); 
                set("value", 50000);

	}
	setup();
}

      int query_autoload() { return 1; } 
