#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(HIM"��Сƽ����"NOR, ({"slap"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�����硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 700);
    set("armor_prop/armor", 60);
  }
  setup();
}
