#include <weapon.h>

inherit FORK;

void create()
{
  set_name("���̲�", ({ "huaici cha", "cha", "fork" }) );
  init_fork(20);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 180);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

