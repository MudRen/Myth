#include <armor.h>

inherit HEAD;

void create()
{
  set_name("Ӳľ��", ({ "ying mukui", "mukui", "kui" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ����ʵ��Ӳľ��������������ơ�\n");
    set("value", 600);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    set("armor_prop/personality", 1);
  }
  setup();
}

