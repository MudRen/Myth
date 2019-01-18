// ���ֱ��� ���ɶ� by Calvin

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIB"���ɶ�"NOR , ({"shenxian dou", "dou"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "��˵����һ���������ϵ�һֻ��è���ߵġ�\n");
    set("value", 300000);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
  call_out ("becoming_old",1800);
}

void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object dan = new (__DIR__"dou");

  dan->move(where);
  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="yangshen dan" && arg!="dou") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*10+random(100));
  me->set("water", (int)me->max_water_capacity()*10+random(100));
  message_vision(HIG "$N����һ�����ɶ�С����������������\n" NOR, me);
  tell_object(me, "���ʱ���ø��б���,��Ƥ��������\n");
  destruct(this_object());
  return 1;
}

