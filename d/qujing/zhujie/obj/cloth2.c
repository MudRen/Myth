#include <armor.h>

inherit CLOTH;

string *names = ({
  "���Ƥ",
  "����Ƥ",
  "�౷Ƥ",
  "��Ƥ",
  "��ţƤ",
  "����Ƥ",
});

string *ids = ({
  "heipi pi",
  "zongxiong pi",
  "qingbei pi",
  "chai pi",
  "maoniu pi",
  "mengma pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "pi", "cloth"}));
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
