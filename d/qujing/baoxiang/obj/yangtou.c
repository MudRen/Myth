// by snowcat oct 15 1997
#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
  set_name("Ѭ��ͷ", ({"yang tou", "yangtou", "tou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻѬ�ú�͸�˵���ͷ��\n");
    set("unit", "ֻ");
    set("value", 200);
    set("food_remaining", 5);
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
  set_name("�еù�����ͷ", ({ "bone" }) );
  set_weight(200);
  set("long", "һֻ�еù�����ͷ��\n");
  return 1;
}
