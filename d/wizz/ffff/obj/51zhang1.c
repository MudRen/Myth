#include <ansi.h>                                                                           
//��һ�Ͷ������£�������ҹ��� 
                       
inherit ITEM;          
                                                                                            
int no_eat(string);                                                                         
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
                                                                                            
int no_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="zhang" && arg!="jinian zhang")   return 1;                                         
    message_vision(HIR "$Nһ�ڰѼ�����������ȥ����һ���û�а������ѵ���
$N��ͷ���Եض��ŵƹ�һ����ԭ������Ľ��������£�
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           




