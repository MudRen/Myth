
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("�����", ({"panlong guai", "guai", "staff"}));
  set_weight(1000);
  if( clonep() )
      set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 5000);
    set("material", "iron");
    set("long", "һ���ںڵ�������ȣ��ϵ�����ͷ��\n");
    set("wield_msg", "$N����һ��$n���ϵ�һ�衣\n");
    set("unequip_msg", "$N��$n�ϵ�һ��������һ����\n");
  }
  init_staff(75);
  setup();
}

