// ������ѥ by Calvin

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
 set_name(HIR"����ѥ"NOR, ({ "feitian shoes", "feixue","flyxue", "shoes" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "����һ˫��ϼ֯�͵����޷�ѥ��\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
set("value", 15000);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
    set("material", "boots");
    set("armor_prop/dodge", 40);
  }
  setup();
}
