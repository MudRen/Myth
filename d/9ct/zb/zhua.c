// ����սצ by Calvin

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIY"͵��սצ"NOR, ({ "toutian zhanzhua","zhanzhua","zhua", "dagger" }) );
 init_dagger(50);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
              set("value", 6000); 
    set("material", "tron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}
