#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("ţβ", ({ "niu wei", "wei", "whip" }) );
  init_whip(7);
  set("unit", "��");
  set_weight(200);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 110);
    set("material", "skin");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

