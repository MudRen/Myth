// gangcha.c

#include <weapon.h>

inherit FORK;

string *names = ({
  "¹�ǲ�",
  "��ǲ�",
  "ţ�ǲ�",
  "Ϭ�ǲ�",
});

void create()
{
  set_name(names[random(sizeof(names))], ({ "cha", "fork" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 300);
    set("material", "bone");
    set("long", "һ���Զ��������ĳ��档\n");
    set("wield_msg", "$N����һ��$n�ٹ�ͷ����\n");
  }
  init_fork(35);
//  set("no_sell",1);
  setup();
}

