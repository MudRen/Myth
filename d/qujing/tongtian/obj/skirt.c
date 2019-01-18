#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "��",
  "��",
  "��",
  "ϸ",
});

string *names = ({
  "��",
  "ɴ",
  "��",
  "��",
});

string *suffixs = ({
  "��ȹ",
  "��ȹ",
  "��ȹ",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"skirt"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 300);
   set("female_only", 1);
   set("material", "cloth");
   set("armor_prop/armor", 1);
   set("armor_prop/dodge", 1);
  }
//  set("no_sell",1);
  setup();
}
