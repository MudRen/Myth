//
#include <ansi.h> 
 
inherit ITEM; 
 
int do_eat(string); 
void init(); 
 
void init() 
{ 
  if (!wizardp(this_player())) { 
    set("no_get", 1); 
    set("no_give", 1); 
    set("no_drop", 1); 
    set("no_sell", 1); 
  } 
    if(this_player()==environment()) 
  add_action("do_eat", "eat"); 
} 
 
void create() 
{ 
  set_name( HIY "������" NOR , ({"hellfire pearl", "pearl"})); 
 
  set_weight(90); 
  if (clonep()) 
    set_default_object(__FILE__); 
  else { 
    set("unit", "��"); 
 
    set("long", "����������������������˵��˾���ʮ�˲�������������ɡ�\n"); 
 
    set("value", 10000); 
    set("drug_type", "��Ʒ"); 
  } 
  set("is_monitored",1); 
  setup(); 
} 
 
int do_eat(string arg) 
{ 
  object me = this_player(); 
  if (arg!="pearl" && arg!="hellfire pearl") return 0; 
 if(me->query("lucky/lianhuo")=="got")
  {tell_object(me,"����̰�ˣ��ٺ٣�\n");return 1;}
  if(me->query("age")<20)
  {tell_object(me,"����̫С�ˣ�addoil!\n");return 1;}
   
  me->set("eff_sen", (int)me->query("max_sen")); 
  me->set("sen", 2*(int)me->query("max_sen")); 
  me->set("eff_gin", (int)me->query("max_gin")); 
  me->set("gin", 2*(int)me->query("max_gin")); 
  me->set("eff_kee", (int)me->query("max_kee")); 
  me->set("kee", 3*(int)me->query("max_kee")); 
  me->set("mana", 2*(int)me->query("max_mana")); 
  me->set("force", 2*(int)me->query("max_force")); 
  me->set("food", 2*(int)me->max_food_capacity()); 
  me->set("water", 2*(int)me->max_water_capacity()); 
  
  me->set("lucky/lianhuo","got");
  me->add("level",10);
  me->add("magic_pointed",100);
  me->add("magiclevel",10);
  me->add("balance",2800000);
  tell_object(me,BBLU HIC"��ĵȼ���ħ���ȼ������10����ħ���������100!\n��Ĵ�������˶��ٰ�ʮ���ƽ�!\n");
  message_vision(HIC "$N����һ�ŵ����𵤣����ڶ�ʱ�е����ȣ�������֮������\n" NOR, me); 
 
  destruct(this_object()); 
  return 1; 
} 
 

