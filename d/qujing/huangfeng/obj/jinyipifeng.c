// created by angell 1/1/2001

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "��������" NOR, ({"jinyi pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���������Ƶ����硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 12500);
    set("armor_prop/spells", 40);
    set ("armor_prop/force", 60);
    set("armor_prop/dodge", 30);
    set("armor_prop/armor", 75);
  }
  setup();
}


