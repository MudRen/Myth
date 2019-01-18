#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "��ɫ",
  "���",
  "����",
  "���",
  "�ϻ�",
});

string *names = ({
  "����",
  "˿��",
  "��ɴ",
  "ϸɴ",
  "��ɴ",
});

string *suffixs = ({
  "��ȹ",
  "սȹ",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"skirt", "cloth"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 200);
   set("material", "leather");
   set("armor_prop/armor", 2);
   set("armor_prop/dodge", 2);
  }
//  set("no_sell",1);
  setup();
}
