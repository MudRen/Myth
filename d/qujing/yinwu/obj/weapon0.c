#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("��β��", ({ "zhiwei jian", "jian", "sword" }) );
  init_sword(36);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 370);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

