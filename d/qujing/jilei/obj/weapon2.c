//Cracked by Roath
#include <weapon.h>

inherit FORK;

void create()
{
  set_name("ţ�ǲ�", ({ "niujiao cha", "cha", "fork" }) );
  init_fork(35);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 110);
    set("material", "bone");
  }
  setup();
}

