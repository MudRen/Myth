#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("�䵶", ({ "jie dao", "dao", "blade" }) );
  init_blade(35);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "metal");
  }
  setup();
}

