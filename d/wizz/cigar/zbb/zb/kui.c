// ������� by Calvin

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
  set_name(MAG"����ħ��"NOR, ({ "poxian mokui", "mokui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","��������ϲ������һ�����ص�ñ��,���Ӳ����Ǻ����ۡ�\n");
             set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 40);
    set("armor_prop/personality", 15);
  }
  setup();
}
