// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "��ù������" , ({"yangshen dan", "dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ų�ù������������ȫ����ë��\n");
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="yangshen dan" && arg!="dan") 
    return 0;
  
  tell_object(me, "��ҩ���ܳ���\n");
  return 1;
}

