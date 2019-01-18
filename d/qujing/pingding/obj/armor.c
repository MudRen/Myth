#include <armor.h>

inherit ARMOR;

string *prefixs = ({
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
});

string *names = ({
  "����",
  "ͭ��",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))],
           ({"armor","jia"}));
  set_weight(20000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 200);
   set("material", "shell");
   set("armor_prop/armor", 20);
   set("armor_prop/dodge", -5);
  }
//  set("no_sell",1);
  setup();
}
