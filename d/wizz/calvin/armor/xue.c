#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
  set_name( MAG"������ѥ"NOR, ({ "liouqi feixue", "feixue","flyxue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "�������������ר��װ����\n");
    set("value", 0);
    set("material", "boots");
    set("armor_prop/dodge", 30);
  }
  setup();
}
