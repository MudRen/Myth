#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( YEL"�ٹ���"NOR, ({"pigu wan", "wan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ųȻ�ɫ�ıٹ��衣\n");
    set("value", 1000);
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
  if (arg!="pigu wan" && arg!="wan") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*3+random(100));
  me->set("water", (int)me->max_water_capacity()*3+random(100));
  message_vision(HIG "$N����һ��СС��"+HIY"�ٹ���"+HIG"������һ�š�\n" NOR, me);
  tell_object(me, "��ʱ����ÿ�������һ���������϶����������ඥ��\n");
  destruct(this_object());
  return 1;
}

