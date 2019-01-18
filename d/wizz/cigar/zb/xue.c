// 六气飞靴 by Calvin

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
 set_name(HIR"飞天靴"NOR, ({ "feitian shoes", "feixue","flyxue", "shoes" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "这是一双晚霞织就的羽绒飞靴。\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
set("value", 15000);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
    set("material", "boots");
    set("armor_prop/dodge", 40);
  }
  setup();
}
