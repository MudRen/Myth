// by snowcat oct 25 1997

#include <armor.h>
inherit CLOTH;

void create()
{
  set_name("����", ({ "gong pao", "pao" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�����ۣ�\n");
    set("unit", "��");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    set("armor_prop/dodge", 10);
  }
  setup();
}

