// shenpao.c
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIY"��������"NOR, ({"sanjie shenpao", "cloth","pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ������,������������ר�õġ�\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 0);
    set("armor_prop/armor", 45);
   set("armor_prop/dodge", 25);
    set("armor_prop/spells", 10);
    set ("armor_prop/force", 45);
    set("armor_prop/parry", 30);
  }
  setup();
}
