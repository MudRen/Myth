// �������� by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIG"������"NOR, ({"biluo shenpao", "cloth","pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���������͸�ľ�ݵĻ������ۡ�\n");
    set("material", "cloth");
    set("unit", "��");
set("value", 10000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
                set("armor_prop/armor", 80);
               set("armor_prop/dodge", 20);
    set("armor_prop/spells", 50);
    set ("armor_prop/force",-50);
    set("armor_prop/parry", -50);
  }
  setup();
}
