#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("��ʯ��ƿ", ({ "hua ping","huaping","ping","vase"}) );
  set_weight(600);
  set_max_encumbrance(6000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "����һֻ���ŷۺ�С������ʯ��ƿ��\n");
    set("value", 2000);
  }
  set("wield_msg", "$N������ʯ��ƿ��С�ĵر����ؿڡ�\n");
  set("unwield_msg", "$N����ʯ��ƿ����ط��¡�\n");
  init_hammer(1);
}

int is_container()
{
  return 1;
}

