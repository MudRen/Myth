#include <weapon.h>

inherit FORK;

void create()
{
  set_name("¹�ǲ�", ({ "lujiao cha", "cha", "fork" }) );
  init_fork(28);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "bone");
  }
  setup();
}

