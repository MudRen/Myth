#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "��ѥ", ({ "yun xue", "yunxue", "xue" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "һ˫������׵���ѥ��\n");
    set("value", 120);
    set("material", "boots");
    set("armor_prop/dodge", 2);
  }
  setup();
}

