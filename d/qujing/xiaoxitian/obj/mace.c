#include <weapon.h>
inherit MACE;

void create()
{
  set_name("����������", ({ "langya bang", "bang", "mace" }));
  set_weight(6000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ���ֶ����������������Ϊ��ʹ��\n");
    set("value", 500);
    set("material", "bronze");
    set("wield_msg", "$Nವ�����һ��$n�������С�\n");
    set("unwield_msg", "$N�����е�$n���¡�\n");
  }
  init_mace(55);
  setup();
}

