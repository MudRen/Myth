#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("����צ", ({ "tie zhua", "zhua", "dagger" }) );
  init_dagger(25);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "tron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

