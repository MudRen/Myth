#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("�߳ݰ�", ({ "qichi pa", "pa", "rake" }) );
  init_rake(35);
  set("unit", "��");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  setup();
}

