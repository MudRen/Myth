//Cracked by Roath
#include <weapon.h>

inherit MACE;

void create()
{
  set_name("ţβ�", ({ "niuwei jian", "jian", "mace" }) );
  init_mace(75);
  set("unit", "��");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "bone");
  }
  setup();
}

