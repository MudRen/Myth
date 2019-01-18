#include <ansi.h>                                                                           
//五一劳动纪念章，给老玩家鼓励 
                       
inherit ITEM;          
                                                                                            
int no_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","你手里一松，纪念章从指间滑落！\n");                                       
    set("no_give","这么珍贵的纪念章，哪能随便给人？\n");                                        
    set("no_drop","这么宝贵的纪念章，扔了多可惜呀！\n");                                        
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIY "五一劳动纪念章" NOR , ({"jinian zhang", "zhang"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "枚");                                                                      
    set("long", "祝你五一劳动节幸福快乐。\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "补品");                                                               
  }                                                                                         
//  set("is_monitored",1);                                                                  
  setup();                                                                                  
}                                                                                           
                                                                                            
int no_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="zhang" && arg!="jinian zhang")   return 1;                                         
    message_vision(HIR "$N一口把纪念章吞了下去，差一点儿没有把门牙硌掉。
$N贼头贼脑地对着灯光一看，原来是真的金属纪念章！
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           




