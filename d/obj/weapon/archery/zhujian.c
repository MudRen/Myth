// zhujian.c ���

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("���", ({ "zhu jian", "arrow", "jian" }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",
"�������ɵļ�����ͷ���⣬��β���Ҳ���Щ��ë��\n");
    set("unit", "��");
    set("base_unit", "֦");
    set("base_weight", 20);
    set("base_value", 10);
  }
  set_amount(10);
  set("value", 100);
  init_archery(10);
  setup();
}

