#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("��ͷ��", ({ "hutou dao", "dao", "blade" }) );
  init_blade(38);
  set("unit", "��");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

