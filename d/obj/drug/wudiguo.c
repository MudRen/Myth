#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init()
{
  add_action("do_eat", "eat");
}
void create()
{
  set_name(RED "�޵й�" NOR, ({"wudi guo","guo"}));
  set_weight(200);
    set("unit", "ö");
    set("long", "\nһö���Ժ����鸣��ɽ��ɫ�����ζ�����۵����档\n");
    set("value", 0);
       set("is_monitored",1); 
    set("drug_type", "��Ʒ");
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  int mana_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
  return notify_fail("��Ҫ��ʲô��\n");  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  if( howold > 432000 ) {
    me->add("maximum_force", 10);
    me->add("max_force", 10);
    me->add("force", 10);
    me->add("maximum_mana", 10);
    me->add("max_mana", 10);
    me->add("mana", 10);
  message_vision(HIW "\n$N����һ��"NOR+HIR"�޵й�"NOR+HIW"��ֻ������Ѫ�����ڣ�������̣�\n"NOR,me);
  destruct(this_object());
  }
  return 1;
}
