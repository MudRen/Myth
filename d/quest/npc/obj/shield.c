#include <armor.h>
#include <ansi.h>
inherit SHIELD;

string *names = ({
  HIY"ϬţƤ��"NOR,
  BLU"��Ƥ��"NOR,
  CYN"��Ƥ��"NOR,
  YEL"��Ƥ��"NOR,
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
  set_weight(1000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 0);
   set("no_put",1);
   set("no_zm",1);
   set("no_give",1);
   set("material", "skin");
   set("armor_prop/armor", 50);
   set("armor_prop/dodge", -40);
  }
  set("no_sell",1);
  setup();
}
