#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("�����", ({ "zhu liaoya", "ya", "dagger" }) );
  init_dagger(15);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 210);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

