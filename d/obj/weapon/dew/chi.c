    //by dewbaby

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name(HIW"ʧȥ������",({"mifan","fan"}));
    set_weight(100);
  if (clonep() )
    set_default_object(__FILE__); 
   else { 
         set("long", "һ��С����:)��\n"); 
         set("unit", "��"); 
        set("value", 9000000); 
     set("food_remaining", 10); 
       set("food_supply", 25); 
  }
}
