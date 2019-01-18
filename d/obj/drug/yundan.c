
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name("�����Ƶ�", ({"yun dan", "dan"}));
  set_weight(90);
  
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ŵ���ɫ�ĵ��裬�������ҩ�����ƶ��ɡ�\n");
    set("value", 100000);
    set("drug_type", "��Ʒ");
  }
  //set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="yun dan")	return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force",(int)me->query("max_force"));
  me->set("food", ((int)me->max_food_capacity())*3);
  me->set("water", ((int)me->max_water_capacity())*3);
  message_vision(HIG "$N�ӻ���С��������ó�һ�ţ��������У���Ȼ��$N��������������⣬�������������˼��ޣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

