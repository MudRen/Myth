// 密林宝库 神仙豆 by Calvin

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIB"神仙豆"NOR , ({"shenxian dou", "dou"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "粒");
    set("long", "传说这是一粒来自天上的一只仙猫尊者的。\n");
    set("value", 800);
    set("no_sell", 1);
    set("drug_type", "补品");
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
  message_vision(HIG "$N捏起一粒神仙豆小心翼翼地送入了嘴里。\n" NOR, me);
  tell_object(me, "你顿时觉得腹中饱涨,肚皮渐渐鼓起。\n");
  destruct(this_object());
  return 1;
}

