// ���ľ� by Calvin

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string *names = ({
  HIY"����"NOR,
});

string *ids = ({
  "ming jing",
  "ming jing",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "ming jing", "jing", "ming"}));
  set_weight(5000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
             set("value", 10000);
                
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
   set("material", "metal");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", 30);
  }
    set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
  setup();
}
