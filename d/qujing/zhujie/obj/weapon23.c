#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("���µ�", ({ "xinyue dao", "dao", "blade" }) );
  init_blade(30);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

