#include <armor.h>

inherit ITEM;

void create()
{
  set_name("�ײ�", ({ "bai bu", "baibu", "bu" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���ײ���\n");
    set("value", 40);
    set("material", "cloth");
  }
  setup();
}

