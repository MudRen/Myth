// zhentian-arrow.c �����

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("�����", ({ "zhentian jian", "arrow", "jian", "zhentian", "zhentian jian", }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",
"��������ǳ��ƹ��ܱ�������֮����������ύ\n��׿ͱ��ɶ����뾩�ǣ�Ҳ��������ˡ�\n");
    set("unit", "��");
    set("base_unit", "֦");
    set("base_weight", 40);
    set("base_value", 500);
  }
  set_amount(18);
  init_archery(80);
  setup();
}

