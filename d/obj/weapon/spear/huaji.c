//sgzl 


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIY "���컭�" NOR, ({ "fangtian huaji","huaji","ji" }));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 10000);
    set("material", "blacksteel");
    set("long", "һ���������Ƶķ��컭ꪡ�\n");
    set("wield_msg", "$N����$n�������У��������ݡ�\n");
  }
  init_spear(40);
  setup();
}

