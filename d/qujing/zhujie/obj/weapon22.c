#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("��", ({ "ge jian", "jian", "sword" }) );
  init_sword(25);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "wood");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

