#include <weapon.h>

inherit HAMMER;
inherit F_LIQUID;

void create()
{
  set_name("���", ({"cha hu", "hu"}));
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ���״ɲ����\n");
    set("unit", "��");
    set("value", 60);
    set("max_liquid", 7);
    set("wield_msg", "$Nץ��һ��$n���������е�������\n");
    set("material", "stone");
  }
  
  set("liquid", ([
                  "type": "water",
                  "name": "���",
                  "remaining": 8,
                  ]) );
  init_hammer(1);
  setup();

}

