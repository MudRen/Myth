#include <armor.h>
#include <ansi.h>
inherit SHIELD;

string *names = ({
  HIY"毞紮嗎"NOR,
  BLU"華儕嗎"NOR,
  CYN"梨錘嗎"NOR,
  YEL"瑞妠嗎"NOR,
});

string *ids = ({
  "tiancan dun",
  "dijing dun",
  "bingling dun",
  "fengshi dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "tian dun", "shield"}));
  set_weight(1000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "璃");
             set("value", 0);
   set("no_zm",1);
   set("material", "skin");
   set("armor_prop/armor", 150);
   set("armor_prop/dodge", -10);
  }
  setup();
}
