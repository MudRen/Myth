#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("��ӧǹ", ({ "hongying qiang", "qiang", "spear" }) );
  init_spear(35);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "iron");
  }
  setup();
}

