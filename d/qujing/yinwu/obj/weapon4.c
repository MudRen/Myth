#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("��Ҷ��", ({ "liuye dao", "dao", "blade" }) );
  init_blade(38);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 380);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

