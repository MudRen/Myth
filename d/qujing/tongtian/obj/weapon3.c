#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("ʯĵ��", ({ "shimu chui", "chui", "hammer" }) );
  init_hammer(25);
  set("unit", "��");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 230);
    set("material", "shell");
  }
  setup();
}

