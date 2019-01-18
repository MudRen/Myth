#include <armor.h>

inherit SHIELD;

string *names = ({
  "��ţƤ",
  "ˮţƤ",
  "Ұ��Ƥ",
  "��¹Ƥ",
  "��Ƥ",
});

string *ids = ({
  "maoniu pi",
  "shuiniu pi",
  "yexiang pi",
  "gonglu pi",
  "chai pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"pi", "shield"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 500);
   set("material", "leather");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
