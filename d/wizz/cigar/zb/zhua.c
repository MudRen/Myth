// 九天战爪 by Calvin

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIG"偷"+HIB"天"+HIR"爪"NOR, ({ "toutian zhua","zhanzhua","zhua", "dagger" }) );
 init_dagger(60);
  set("unit", "根");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
                set("value", 200000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "这种罕见的装备可不是随便可以买卖的!\n");
    set("material", "tron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}
