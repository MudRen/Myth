#include <armor.h>

inherit HEAD;

void create()
{
  set_name("��˿ñ", ({ "si mao", "mao" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ�����ĺ�ɫ˿ñ��\n");
    set("value", 300);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

