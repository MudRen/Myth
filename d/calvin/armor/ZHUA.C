#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIW"����սצ"NOR, ({ "jiutian zhanzhua","zhanzhua","zhua", "dagger" }) );
  init_dagger(65);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 0);
    set("material", "tron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}
