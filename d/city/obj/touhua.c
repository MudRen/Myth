//Last Create  By PKYOU@DHXY 2002/05/28
#include <armor.h>

inherit FINGER;

void create()
{
  set_name("����ָ��", ({ "zhi huan", "zhihuan", "ring" }));
  set("weight", 800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 3000);
    set("material", "silver");
    set("armor_prop/armor", 3);
    set("armor_prop/personality", 1);
  }
  setup();
}       

