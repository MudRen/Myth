// created 3/31/1997 by snowcat
#include <weapon.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ִɲ���", ({ "cuci chawan", "chawan", "wan", "tea" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "����һֻ�ִɲ��롣\n");
    set("unit", "ֻ");
    set("value", 40);
    set("max_liquid", 80); 
  }

  set("liquid", ([
    "type": "tea",
    "name": "����",
    "remaining": 80,
  ]) );
  setup();
}
