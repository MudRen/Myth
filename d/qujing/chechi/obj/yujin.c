// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("ԡ��", ({"yu jin", "yujin", "jin"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�������Ĵֲ���ԡ��\n");
    set("wear_msg", "$N��ԡ��չ������ϸ�ع������ϡ�\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 110);
    set("armor_prop/armor", 4);
  }
  setup();
}

