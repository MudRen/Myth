#include <ansi.h>                                                                           
//��һ�Ͷ������£�������ҹ��� 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","������һ�ɣ������´�ָ�们�䣡\n");                                       
    set("no_give","��ô���ļ����£����������ˣ�\n");                                        
    set("no_drop","��ô����ļ����£����˶��ϧѽ��\n");                                        
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIY "��һ�Ͷ�������" NOR , ({"jinian zhang", "zhang"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "ö");                                                                      
    set("long", "ף����һ�Ͷ����Ҹ����֡�\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "��Ʒ");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="zhang" && arg!="jinian zhang")   return 0;                                         
                                                                                            
  me->set("eff_sen", (int)me->query("max_sen"));                                            
  me->set("sen", (int)me->query("max_sen"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_kee", (int)me->query("max_kee"));                                            
  me->set("kee", (int)me->query("max_kee"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("force", (int)me->query("max_force"));                                            
  me->add("potential",500);                                            
  me->add("office_number",1); 
  me->add("combat_exp",2000);
  me->add("daoxing",5000);
  me->add("balance",100000);   message_vision(HIR "$Nһ�ڰѼ�����������ȥ����ȻӲ��һ��������ǻ������ɿڵġ
$N�����˵������꣬��ѧ2000�㣬Ǳ��500�㣬��ְ1�㣬����10gold���                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           



