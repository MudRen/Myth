#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("˫ͷì", ({ "shuangtou mao", "mao", "spear" }) );
  init_spear(30);
  set("unit", "��");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 480);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

