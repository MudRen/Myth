// �������� by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(YEL"��������"NOR, ({"sanjie shenpao", "cloth","pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���������͸�ľ�ݵĻ������ۡ�\n");
    set("material", "cloth");
    set("unit", "��");
             set("value", 0);
                set("armor_prop/armor", 80);
   set("armor_prop/dodge", 50);
    set("armor_prop/spells", 50);
    set ("armor_prop/force",20);
    set("armor_prop/parry", -20);
  }
  setup();
}
