#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("ˮӡ��ȹ", ({ "hua qun", "qun", "skirt" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ����ɫˮӡ��ȹ��\n");
    set("unit", "��");
    set("value", 500);
    set("material", "cloth");
    set("female_only", 1);
    set("armor_prop/armor", 1);
    set("armor_prop/dodge", 1);
  }
  setup();
}

