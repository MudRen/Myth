#include <armor.h>

inherit HEAD;

void create()
{
  set_name("��ͷ��", ({ "tou jin", "toujin", "jin" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���Ĳ�ͷ��\n");
    set("value", 80);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

