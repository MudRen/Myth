#include <weapon.h>

inherit AXE;

void create()
{
  set_name("��Ǹ�", ({ "suigu fu", "fu", "axe" }) );
  init_axe(30);
  set("unit", "��");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

