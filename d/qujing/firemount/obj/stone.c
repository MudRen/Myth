// created by snowcat on 4/12/1997
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("ʯͷ", ({"stone", "shi tou"}));
  set_weight(4000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "һ�������нǵ�ʯ�顣\n");
    set("material", "stone");
  }
  init_hammer(1);
  setup();
}

