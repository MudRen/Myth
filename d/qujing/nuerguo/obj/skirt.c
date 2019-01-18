// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string *names = ({
  "ӡ��ȹ",
  "����Ͳȹ",
  "ˮȾ��ȹ",
  "�����س�ȹ",
  "����ȹ",
});

void create()
{
  set_name(names[random(sizeof(names))], ({ "skirt", "cloth" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ������Ů����ȹ�ӡ�\n");
    set("unit", "��");
    set("material", "cloth");
    set("armor_prop/armor", 3);
    set("armor_prop/personality", 4);
    set("female_only", 1);
    set("value",200);
  }
  setup();
}

