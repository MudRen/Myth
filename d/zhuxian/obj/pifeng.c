// by snowcat oct 15 1997
#include <ansi.h>

#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIG "��������" NOR, ({"xianling pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�����硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 700);
    set("armor_prop/armor", 135);
    set("armor_prop/armor_vs_force", 600);
  }
  setup();
}


