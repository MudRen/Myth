#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("����", ({ "tie lian", "lian", "whip" }) );
  init_whip(35);
  set("unit", "��");
  set_weight(850);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "iron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

