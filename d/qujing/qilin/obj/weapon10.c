#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("������", ({ "xiangya jian", "jian", "sword" }) );
  init_sword(45);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 510);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

