// ľ�� by Cigar

#include <armor.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit BOOTS;

void create()
{
 set_name(HIY"ľ��"NOR, ({ "mu ji","shoes", "xie" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
                set("is_monitored", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
  set("replace_file", "/d/quest/longzhu/armor/mujifake.c");
  set("unique", 1);
                set("name_recognized", "ľ��");
    set("long", CYN"����������˹��ѥ�ӣ���˵��������������������ġ�\n"NOR);
                set("value", 0);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
    set("material", "boots");
      set("armor_prop/armor", 120);
    set("armor_prop/dodge", 120);
  }
  setup();
}
