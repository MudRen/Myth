#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("������", ({ "kusong zhang", "zhang", "staff" }) );
  init_staff(20);
  set("unit", "��");
  set_weight(550);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

