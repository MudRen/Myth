#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("��Ƥ��", ({ "bopi bian", "bian", "whip" }) );
  init_whip(40);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

