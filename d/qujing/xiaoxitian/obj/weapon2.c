#include <weapon.h>

inherit FORK;

void create()
{
  set_name("��ͭ��", ({ "qingtong cha", "cha", "fork" }) );
  init_fork(40);
  set("unit", "��");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 360);
    set("material", "bone");
  }
  setup();
}

