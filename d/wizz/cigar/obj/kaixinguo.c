// ���Ĺ� by Cigar

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIY"����"+HIW"���Ĺ�"NOR , ({"kaixin guo","guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", HIR"ͫͫ��ϲ������ʳ�����Ĺ��ʣ��������һ��Ũ��������ǣ����滹��׺�ſ�С֥�顣\n"NOR);
    set("value", 0);
set("no_sell",1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
  call_out ("becoming_old",1800);
}
void becoming_old ()
{
  object me = this_object();

  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="kaixin guo" && arg!="guo") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*10+random(100));
  me->set("water", (int)me->max_water_capacity()*10+random(100));
  message_vision(HIG "$N�����ĳ���һ��"+HIY"����"+HIW"���Ĺ�"+HIG"�����ĵĲ����ˣ������ۣ�  Ц�ö����ۣ���������ﳪ�ģ������㣬���㣬���μ��ľ����㣬��������������������㡱�� \n"   NOR, me);
  tell_object(me, HIM"�����ۣ���Եö����ۣ����󻨶����ڴ�������ڴ�����... ... ͫͫ����ԵĿ��Ĺ��ó�������ͫͫ��... ...\n");
  destruct(this_object());
  return 1;
}
