#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
  set_name(HIB"�������"NOR, ({ "wuyu qikui", "qikui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","������������ר�õ�װ����\n");
    set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 45);
    set("armor_prop/personality", 1);
  }
  setup();
}
