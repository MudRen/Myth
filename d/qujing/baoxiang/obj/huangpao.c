// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("����", ({"huang pao", "cloth"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ��׺�����鱦ʯ�Ļ��ۡ�\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 20000);
    set("armor_prop/armor", 30);
  }
  setup();
}

