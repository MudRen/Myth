#include <weapon.h>

inherit STICK;

void create()
{
  set_name("�����", ({ "daguo gun", "gun", "stick" }) );
  init_stick(25);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 150);
    set("material", "iron");
  }
  setup();
}

