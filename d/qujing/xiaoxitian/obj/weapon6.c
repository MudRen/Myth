#include <weapon.h>

inherit STICK;

void create()
{
  set_name("�ջ��", ({ "shaohuo gun", "gun", "stick" }) );
  init_stick(15);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 100);
    set("material", "bone");
  }
  setup();
}

