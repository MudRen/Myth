// rou.c 	ȡ������

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "ȡ������" NOR, ({"qujingren rou","renrou","rou"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���µ�����,���˿��Գ�������,���������ӷ�����\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }

  set("is_monitored",1);  
  setup();
}

int do_eat(string arg)
{
  object who = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
//  me->set("food", (int)me->max_food_capacity());
  who->delete("no_qujing");
  destruct(this_object());
  return 1;
}

