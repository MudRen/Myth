#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("��ʯ��", ({ "qingshi chui", "chui", "hammer" }) );
  init_hammer(24);
  set("unit", "��");
  set_weight(1200);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 130);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

