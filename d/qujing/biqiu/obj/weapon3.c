#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("������", ({ "liutiao bian", "bian", "whip" }) );
  init_whip(18);
  set("unit", "��");
  set_weight(400);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 75);
    set("material", "wood");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

