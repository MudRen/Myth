#include <armor.h>
#include <ansi.h>
inherit SHIELD;

string *names = ({
  HIY"���"NOR,
  BLU"���"NOR,
  CYN"�׶�"NOR,
  HIW"ѩ��"NOR,
});

string *ids = ({
  "feng dun",
  "yu dun",
  "lei dun",
  "xue dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "tian dun", "shield"}));
  set_weight(1000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
set("value", 13000);
                set("no_give", 1);
                                set("no_drop", 1);
   set("no_put",1);
   set("no_zm",1);
   set("no_give",1);
   set("material", "skin");
   set("armor_prop/armor", 60);
               set("armor_prop/dodge", -10);
  }
   set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
  setup();
}
