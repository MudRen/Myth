// by smile 12/08/1998
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "��Ƥ����" NOR, ({"baigu pifeng", "pifeng"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ��Ѫ���ܵ���Ƥ����,������ɢ����һ��Ѫ��ζ��\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 2000);
    set("armor_prop/armor", 50);
    set("armor_prop/courage",8);
  }
  setup();
}


