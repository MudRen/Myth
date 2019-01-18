#include <ansi.h>

inherit ITEM;

int do_eat(string);
int give_reward(object);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIM "���" NOR, ({"pan tao","pantao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
//    set("long", "һ�ң�����˴������Ρ�\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
    set("reward_value",1);
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player(),taohe;
  int food_allowed=(int)me->max_food_capacity()-me->query("food");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  if (food_allowed<0) {
     message_vision(HIM"$N��Ƥ��������һö��ң����ö����͵����ܡ�\n"NOR,me);
     destruct(this_object());
     return 1;
  }
  message_vision(HIM "$N����һö��ң�ֻ���ڽ������泩�ޱȣ��̲�ס��У��óԣ���Ҫ�� \n" NOR, me);
  me->set("food",me->query("food")+30);
  give_reward(me);  
  
  taohe=new (__DIR__"taohe");
  taohe->move(me);  
  destruct(this_object());

  return 1;
}

int give_reward(object me) {
  int tao_eaten;

//  if (me->query("title")!="�����ʥ") return 0;
//  if (me->query("dntg/pantao")=="done") return 0;
  if ((int)me->query("dntg/pantao_eaten") )
       tao_eaten=(int)me->query("dntg/pantao_eaten");
  else tao_eaten=0;
  if (tao_eaten>=7) {
     if (random(2)) {
       me->add_maximum_force(query("reward_value"));
       me->add_maximum_mana(query("reward_value"));
    } else
    {
       me->add_maximum_force(-1);
       me->add_maximum_mana(-1);
       tell_object(me,HIR"��ͻȻ����������Ѫ��ӿ����������˵���������ܣ�\n"NOR);
    }
    return 0;
}
  tao_eaten++;
  me->set("dntg/pantao_eaten",tao_eaten);
    me->add_maximum_force(1+random(15*(int)query("reward_value") ));
    me->add_maximum_mana(1+random(15*(int)query("reward_value")));
  return 1;
}  
