//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("ţ����", ({ "niutui zhang", "zhang", "staff" }) );
  init_staff(35);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 410);
    set("material", "bone");
  }
  setup();
}

