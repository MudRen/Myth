#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("��ɽ��", ({ "zhushan pa", "pa", "rake" }) );
  init_rake(35);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "iron");
  }
  setup();
}

