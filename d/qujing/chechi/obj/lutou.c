// by snowcat oct 29 1997
#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
  set_name("��¹ͷ", ({"bai lutou", "lutou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ��ɫ¹ͷ��\n");
    set("unit", "ֻ");
    set("value", 1000);
    set("food_remaining", 6);
    set("food_supply", 40);
    set("wield_msg", "$Nץ��һֻ$n��������\n");
    set("material", "bone");
  }
  init_hammer(1);
  setup();
}

int finish_eat()
{
  if( !query("weapon_prop") )
    return 0;
  set_name("�еù���¹ͷ", ({ "bone" }) );
  set_weight(200);
  set("long", "һֻ�еù���¹ͷ��\n");
  return 1;
}
