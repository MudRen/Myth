// �߾����� by Calvin

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIC"�߾�����"NOR, ({"qijue pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�ഫ�����ɫ�������Ǿ���̨���ĵ�һ�����\n");
    set("material", "leather");
    set("unit", "��");
             set("value", 12000);
    set("armor_prop/armor", 50);
    set("armor_prop/spells", 20);
    set ("armor_prop/force", 20);
    set("armor_prop/parry", 50);
  }
  setup();
}
