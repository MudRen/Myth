#include <armor.h>

inherit SURCOAT;
#include <ansi.h>
void create()
{
  set_name(HIC"����޼�"NOR, ({"zhitao"}));
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
