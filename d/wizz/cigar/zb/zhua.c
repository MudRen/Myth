// ����սצ by Calvin

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIG"͵"+HIB"��"+HIR"צ"NOR, ({ "toutian zhua","zhanzhua","zhua", "dagger" }) );
 init_dagger(60);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
                set("value", 200000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
    set("material", "tron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}
