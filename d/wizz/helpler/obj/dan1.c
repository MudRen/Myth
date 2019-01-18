
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
 //   set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "�𱦱��Ļ��ǵ�" NOR , ({"shengri dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�Ž��ɫ�Ľ𱦱��Ļ��ǵ����裬��΢���ŵ�Щ��������\n");
    set("value",20000);

    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
if ( (int)me->query("shengao" )>3) return notify_fail ( "���˾��ٱ�̰����!\n");

  if (arg!="dan") return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", 2*(int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", 2*(int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", 2*(int)me->query("max_kee"));
  me->set("mana", 2*(int)me->query("max_mana"));
  me->set("force", 2*(int)me->query("max_force"));
  me->set("food", 2*(int)me->max_food_capacity());
  me->set("water", 2*(int)me->max_water_capacity());
//  me->add("daoxing",20000);
me->set("shengao",4);

  me->add("potential",25000);

me->add("combat_exp",50000);
  message_vision(HIG "$N��������һ�Ž𱦱��Ļ��ǵ��������У�һʱ���������硣
ֻ��$N���������������Σ��������о�����ˣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

