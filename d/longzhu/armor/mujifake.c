// ľ��(���) by Cigar

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
 set_name(HIY"ľ��"NOR, ({ "mu ji","shoes", "xie" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
    set("long", CYN"����������˹��ѥ�ӣ���˵��������������������ġ�\n"NOR);
                set("value", 0);
    set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
  set("fake", 1);
    set("material", "boots");
      set("armor_prop/armor", 20);
    set("armor_prop/dodge", 20);
  }
  setup();
}
