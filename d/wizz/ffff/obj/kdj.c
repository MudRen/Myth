#include <ansi.h>                                                                           
//½¨Õ¾¹±Ï×¼ÍÄî½±Àø£¬¸øÀÏÍæ¼Ò¹ÄÀø 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","Äã×öÃÎÈ¥°É£¡\n");                                       
    set("no_give","ÕâÃ´Õä¹óµÄ¶«Î÷£¬ÄÄÄÜËæ±ã¸øÈË£¿\n");                                        
    set("no_drop","ÈÓÁË¶à¿ÉÏ§Ñ½,±¿µ°£¡\n");                                        
    set("no_sell","·²ÈËÄÄÀïÖªµÀ"+this_object()->query("name")+"µÄ¼ÛÖµ£¿»¹ÊÇ×Ô¼ºÁô×Å°É¡£\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIM "¿ÏµÂ»ù¶ùÍ¯Ì×²Í" NOR , ({"kendeji taocan", "kdj"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "Ì×");                                                                      
    set("long", "¸ĞĞ»Äã¶ÔÓÚÉß¿ÚÕ¾µÄ¹±Ï×£¡\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "²¹Æ·");                                                               
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
  me->add("balance",1000000);   message_vision(HIR "$NÍµÍµµØ¶Ë³öåçĞÇ´óÊå½±Àø¸ø$PµÄ¿ÏµÂ»ù¶ùÍ¯Ì×²Í£¬¿ªÊ¼ÂıÂıµØÆ·³¢ÆğÀ´¡£¡
$NÔö¼ÓÁËµÀĞĞÊ®ÎåÄê£¬ÎäÑ§2000µã£¬Ç±ÄÜ1000µã£¬¹ÙÖ°1µã£¬´¢Ğî100gold£¡£                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           

