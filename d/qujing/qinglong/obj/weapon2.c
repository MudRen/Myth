#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("���Ǵ�", ({ "hugu ci", "ci", "dagger" }) );
  init_dagger(11);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 180);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

