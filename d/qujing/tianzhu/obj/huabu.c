#include <armor.h>

inherit ITEM;

void create()
{
  set_name("����", ({ "hua bu", "huabu", "bu" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��󻨲���\n");
    set("value", 50);
    set("material", "cloth");
  }
  setup();
}

