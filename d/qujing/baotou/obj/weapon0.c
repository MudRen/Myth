#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("����ذ", ({ "danren bi", "bi", "dagger" }) );
  init_dagger(15);
  set("unit", "��");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 120);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

