//Cracked by Roath

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
    add_action("do_eat", "eat");
}

void create()
{
  set_name(HIW "������" NOR, ({"heshouwu","wu"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���ֺ���׳�ĺ����ڡ�\n");
        set("drug_type", "��Ʒ");
  }
  
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  int howold;
  howold = (int)me->query("mud_age") + (int)me->query("age_modify");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());

    me->add_maximum_force(2);
    me->add_maximum_mana(2);

  message_vision(HIG "$N����һ�ź����ڣ����Ϸ���һƬ��⡣\n" NOR, me);
  
  if( howold > 1382400 ) {
    me->add("age_modify", -1200);
    me->add("age_modify_time", 1);
  }
  destruct(this_object());
  return 1;
}

