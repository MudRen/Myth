#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("����", ({"bai pao", "pao"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","һ����ɫ����˿�ۣ�������ʡ�\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 200);
    set("armor_prop/armor", 4);
  }
  setup();
}

