#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("����ǹ", ({ "biluo qiang", "qiang", "spear" }) );
  init_spear(40);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

