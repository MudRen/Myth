// by snowcat oct 29 1997
#include <weapon.h>

inherit ITEM;

void create()
{
  set_name("ʨ��ͷ", ({"shizi tou", "tou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ�����뿳�ϵ�ʨ��ͷ��\n");
    set("unit", "ֻ");
    set("material", "bone");
  }
  setup();
}

