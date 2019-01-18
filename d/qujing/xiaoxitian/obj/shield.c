#include <armor.h>

inherit SHIELD;

string *names = ({
  "ϬţƤ��",
  "��Ƥ��",
  "��Ƥ��",
  "��Ƥ��",
});

string *ids = ({
  "xiniupi dun",
  "xiongpi dun",
  "xiangpi dun",
  "hupi dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "shield"}));
  set_weight(10000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 500);
   set("material", "skin");
   set("armor_prop/armor", 20);
   set("armor_prop/dodge", -3);
  }
  set("no_sell",1);
  setup();
}
