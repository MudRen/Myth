// �˲����� by Calvin

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

string *names = ({HIM"��������"NOR,});

string *ids = ({
   "ziyu longwan" 
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "hu wan", "wan", "wrists"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
             set("value", 0);
   set("material", "metal");
   set("armor_prop/armor", 40);
   set("armor_prop/force", 20);
  }
  setup();
}
