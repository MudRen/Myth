#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("�״ɻ���", ({ "hua pen","huapen","pen"}) );
  set_weight(600);
  set_max_encumbrance(6000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "����һֻ�׵������Ĵɻ��衣\n");
    set("value", 500);
  }
  set("wield_msg", "$N����״ɻ��裬С�ĵر����ؿڡ�\n");
  set("unwield_msg", "$N���״ɻ�������ط��¡�\n");
  init_hammer(1);
}

int is_container()
{
  return 1;
}

