
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "������" , ({"lengxiang wan", "wan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�����۴��ҩ�裬�н�Ƣ��θ����������֮Ч��\n");
    set("value", 800);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
  call_out("self_dest",600);
}

void self_dest()
{
    object env;
    if(this_object()) {
	if(env=environment(this_object()))
	    tell_object(env,name()+"���ڵ��ϲ����ˡ�\n");
	destruct(this_object());
    }
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int food,water;
  object me = this_player();
  if (arg!="lengxiang wan" && arg!="wan") 
    return 0;
  
  food=(int)me->max_food_capacity()/2+random(120)-60;
  water=(int)me->max_water_capacity()/2+random(120)-60;
  if (me->query("food")>food) me->set("food",food);
  if (me->query("water")>water) me->set("water",water);

  message_vision(HIG "$N����һ���������ͽ��������¡�\n" NOR, me);
  tell_object(me, HIG"��ʱ�����һ������֮�������������������ߣ�����֮����˵��������̹��\n"NOR);
  destruct(this_object());
  return 1;
}
