#include <armor.h>
#include <ansi.h>

inherit WRISTS;

string *names = ({CYN"�˲�����"NOR,});

string *ids = ({
   "babu longwan" 
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "hu wan", "wan", "wrists"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "ֻ");
   set("value", 0);
   set("material", "metal");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", -5);
  }
  set("no_sell",1);
  setup();
}
