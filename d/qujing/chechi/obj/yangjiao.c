// by snowcat oct 29 1997
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("�����", ({"hui yangjiao", "yangjiao"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����ɫ��ǡ�\n");
    set("unit", "��");
    set("value", 1000);
    set("wield_msg", "$Nץ��һ��$n��������\n");
    set("material", "bone");
  }
  init_hammer(1);
  setup();
}

