#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("���",({ "zhu pa","zhupa", "pa", "rake" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("material", "bamboo");
    set("long", "����һ�ѳ�������ҡ�\n");
    set("wield_msg", "$N�ó�һ��$n���������С�\n");
    set("unequip_msg", "$N�������е�$n��\n");
  }
  init_rake(10);
  setup();
}
