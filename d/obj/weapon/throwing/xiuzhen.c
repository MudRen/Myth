//Cracked by Roath
// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
   set_name("�廨��", ({"xiuhua zhen","zhen"}));
   if( clonep() )
            set_default_object(__FILE__);
   else 
     {
      set("long",    "һ��ϸС���廨�룬���ŵ�㺮â��\n");
      set("unit", "��");
      set("base_unit", "��");
      set("base_weight", 5);
      set("can_install", 1);
      set("value", 30);
      }
      set_amount(10);
      init_throwing(10);
      setup();
}

