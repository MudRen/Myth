#include <armor.h>

inherit HEAD;

void create()
{
  set_name("���", ({ "jin fengguan", "fengguan", "guan" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ��˿�ʵĽ�ɫ��ڣ��������Ž�\n");
    set("value", 400);
    set("material", "silk");
    set("female_only", 1);
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

