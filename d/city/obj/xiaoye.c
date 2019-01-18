//by cigar 2001.12

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG "��ɫСҶ" NOR, ({"xiao ye", "ye"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "Ƭ");
    set("long", HIG "һƬ������ɫ΢���СҶ�ӡ�\n"NOR);
    set("value", 800);
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

  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xiao ye" && arg!="ye") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*3+random(120));
  me->set("water", (int)me->max_water_capacity()*3+random(120));
  message_vision(HIG "$N����һƬ��ɫСҶ������У�СҶ��ڼ�����$N�ٸо������\n" NOR, me);
  tell_object(me,HIG "������̹���ˣ�\n"NOR);
  destruct(this_object());
  return 1;
}
