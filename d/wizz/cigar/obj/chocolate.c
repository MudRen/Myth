// �ɿ��� by Cigar

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIW"��ܽ�ɿ���"+HIG"̫����"NOR , ({"qiaoke li", "taifei tang","tang"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", HIB"ŨŨ���ɿ���ζ������������ζ�������ٿ����ҾͳԵ��㡣\n"NOR);
    set("value", 0);
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
  if (arg!="qiaoke li" && arg!="tang") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*20+random(100));
  me->set("water", (int)me->max_water_capacity()*20+random(100));
   message_vision(HIM "$N�����ĳ���һ��"+HIW"��ܽ�ɿ���"+HIG"̫����"+HIM"�����𰡣�������ζ  ��������ĸо�������ġ�ŨŨ�ģ�Ҳ��֪��ʱ���쳤�ؾ��ƺ��ѱ�Ĳ԰�����������ʯ������ȴ�����ޣ���֮���֮�У���������ɽ�ˣ�������ĵ��ϣ��ҵ���ֻΪ�����Ծ...\n" NOR, me);
  tell_object(me, HIY"������Ȼ��������ͯ����Ľ�֡� �����㵽��ĵ��ϡ�\n");
  destruct(this_object());
  return 1;
}
