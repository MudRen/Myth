#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "��ɽ��", ({ "dengshan ji", "ji" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "һ˫���ʵĵ�ɽ�졣\n");
    set("value", 80);
    set("material", "boots");
    set("armor_prop/dodge", 2);
  }
  setup();
}

