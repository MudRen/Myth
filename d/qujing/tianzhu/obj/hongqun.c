#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("���ȹ", ({ "hong qun", "qun", "skirt" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�����ɫ��ȹ������С���롣\n");
    set("unit", "��");
    set("value", 2000);
    set("material", "cloth");
    set("female_only", 1);
    set("armor_prop/armor", 5);
    set("armor_prop/dodge", 5);
  }
  setup();
}

