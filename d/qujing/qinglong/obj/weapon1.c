#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("ʨ�ȹ�", ({ "shitui gu", "gu", "staff" }) );
  init_staff(20);
  set("unit", "��");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 260);
    set("material", "metal");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

