// ������ѥ by Calvin

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
  set_name(HIR"̤�Ʒ�ѥ"NOR, ({ "tayun feixue", "shoes","flyxue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "����һ˫��ϼ֯�͵����޷�ѥ��\n");
             set("value", 0);
    set("material", "boots");
    set("armor_prop/dodge", 100);
    set("armor_prop/armor", 30);
  }
  setup();
}
