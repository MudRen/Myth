
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","���ֹ���ֵ����Ǯ������Ҳû��ͷ��\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name( GRN "Ұ����" NOR , ({"lizi", "guo"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ����ɫ�Ĺ�ʵ������ȥ�����Ǻܳ��졣\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="guo" && arg!="lizi")	return 0;
  
  me->set("sen", (int)me->query("max_sen"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N������һҧ���ۣ���������ζ����á�$N����һ��·;������о���û�ˡ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

