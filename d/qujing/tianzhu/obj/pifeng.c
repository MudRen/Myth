#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("��������", ({ "zirong pifeng", "pifeng" }) );
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "cloth");
    set("value", 400);
    set("armor_prop/armor", 2);
  }
  setup();
}

