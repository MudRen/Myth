#include <weapon.h>

inherit FORK;

void create()
{
  set_name("÷��¹��", ({ "meihualu jiao", "jiao", "fork" }) );
  init_fork(22);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

