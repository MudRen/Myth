#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("�Ļ���", ({ "tanghua jian", "jian", "sword" }) );
  init_sword(35);
  set("unit", "��");
  set_weight(750);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

