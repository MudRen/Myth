#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("���",({ "zhu bian","zhubian", "bian", "whip" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("material", "bamboo");
    set("long", "����һ����������ޡ�\n");
    set("wield_msg", "$N�ó�һ��$n���������С�\n");
    set("unequip_msg", "$N�������е�$n��\n");
  }
  init_whip(10);
  setup();
}
