#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("��β��", ({ "fengwei bian", "bian", "whip" }) );
  init_whip(35);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 410);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

