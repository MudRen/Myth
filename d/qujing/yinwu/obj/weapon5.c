#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("¹Ƥ��", ({ "lupi bian", "bian", "whip" }) );
  init_whip(20);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "skin");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

