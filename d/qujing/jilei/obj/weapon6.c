//Cracked by Roath
#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("ţ����", ({ "niujiao ren", "ren", "dagger" }) );
  init_dagger(15);
  set("unit", "��");
  set_weight(200);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 250);
    set("material", "bone");
  }
  setup();
}

