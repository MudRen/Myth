#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("�����", ({ "fengbeng dao", "dao", "blade" }) );
  init_blade(25);
  set("unit", "��");
  set_weight(400);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 230);
    set("material", "shell");
  }
  setup();
}

