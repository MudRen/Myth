// by snowcat 11/22/1997

#include <armor.h>

inherit FINGER;

void create()
{
  set_name("�Ͻ��ָ", ({ "zijin jiezhi", "jiezhi", "ring" }));
  set("weight", 100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}
