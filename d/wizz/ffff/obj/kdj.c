#include <ansi.h>                                                                           
//��վ���׼������������ҹ��� 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","������ȥ�ɣ�\n");                                       
    set("no_give","��ô���Ķ��������������ˣ�\n");                                        
    set("no_drop","���˶��ϧѽ,������\n");                                        
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIM "�ϵ»���ͯ�ײ�" NOR , ({"kendeji taocan", "kdj"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "��");                                                                      
    set("long", "��л������߿�վ�Ĺ��ף�\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "��Ʒ");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="kdj" && arg!="kendeji taocan")   return 0;                                         
                                                                                            
  me->set("eff_sen", (int)me->query("max_sen"));                                            
  me->set("sen", (int)me->query("max_sen"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_kee", (int)me->query("max_kee"));                                            
  me->set("kee", (int)me->query("max_kee"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("force", (int)me->query("max_force"));                                            
  me->add("potential",1000);                                            
  me->add("office_number",1); 
  me->add("combat_exp",2000);
  me->add("daoxing",15000);
  me->add("balance",1000000);   message_vision(HIR "$N͵͵�ض˳����Ǵ��影����$P�Ŀϵ»���ͯ�ײͣ���ʼ������Ʒ���������
$N�����˵���ʮ���꣬��ѧ2000�㣬Ǳ��1000�㣬��ְ1�㣬����100gold���                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           

