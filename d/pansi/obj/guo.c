// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( YEL"�޻���"NOR, ({"wuhua guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "��˵�����޻������Գ������ϡ�\n");
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
  if (arg!="wuhua guo" && arg!="guo") 
      return notify_fail("��Ҫ��ʲô��\n");
  
//  if (me->query("family/family_name") != "��˿��" ) return notify_fail("�㲻����˿���£�����ӿɳԲ��ã�\n");
  
  me->set("food", (int)me->max_food_capacity()*3+random(100));
  me->set("water", (int)me->max_water_capacity()*3+random(100));
  message_vision(HIG "$N����һö�޻���������һ�š�\n" NOR, me);
  tell_object(me, "��ʱ����ÿ�������һ���������϶����������ඥ��\n");
  destruct(this_object());
  return 1;
}
