#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("��ɽ��", ({ "kanshan dao", "dao", "blade" }) );
  init_blade(35);
  set("unit", "��");
  set_weight(750);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

