// created by angell 1/1/2001
// room: /d/qujing/huangfeng/obj/hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("��Ƥ", ({"hu pi", "pi"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���ϻ�Ƥ��ëɫ�������������е�ɡ�\n");
    set("material", "leather");
    set("unit", "��");
    set("armor_prop/armor", 15);
  }
  setup();
}

