
#include <weapon.h>

inherit FORK;

void create()
{
  set_name("���ǲ�", ({ "dragon fork", "fork" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 300);
    set("material", "bone");
    set("long", "һ������������ĳ��档\n");
    set("wield_msg", "$N����һ��$n�ٹ�ͷ����\n");
  }
  init_fork(35);
  setup();
}

