#include <weapon.h>

inherit AXE;

void create()
{
  set_name("ӥ�츫", ({ "yingzui fu", "fu", "axe" }) );
  init_axe(28);
  set("unit", "��");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 130);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

