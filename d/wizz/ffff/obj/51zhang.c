#include <ansi.h>                                                                           
//ÎåÒ»ÀÍ¶¯¼ÍÄîÕÂ£¬¸øÀÏÍæ¼Ò¹ÄÀø 
                       
inherit ITEM;          
                                                                                            
int do_eat(string);                                                                         
void init();                                                                                
                                                                                            
void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","ÄãÊÖÀïÒ»ËÉ£¬¼ÍÄîÕÂ´ÓÖ¸¼ä»¬Âä£¡\n");                                       
    set("no_give","ÕâÃ´Õä¹óµÄ¼ÍÄîÕÂ£¬ÄÄÄÜËæ±ã¸øÈË£¿\n");                                        
    set("no_drop","ÕâÃ´±¦¹óµÄ¼ÍÄîÕÂ£¬ÈÓÁË¶à¿ÉÏ§Ñ½£¡\n");                                        
    set("no_sell","·²ÈËÄÄÀïÖªµÀ"+this_object()->query("name")+"µÄ¼ÛÖµ£¿»¹ÊÇ×Ô¼ºÁô×Å°É¡£\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           
                                                                                            
void create()                                                                               
{                                                                                           
  set_name( HIY "ÎåÒ»ÀÍ¶¯¼ÍÄîÕÂ" NOR , ({"jinian zhang", "zhang"}));                                     
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "Ã¶");                                                                      
    set("long", "×£ÄãÎåÒ»ÀÍ¶¯½ÚĞÒ¸£¿ìÀÖ¡£\n");                                                
    set("value", 0);                                                                        
    set("drug_type", "²¹Æ·");                                                               
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
  me->add("balance",100000);   message_vision(HIR "$NÒ»¿Ú°Ñ¼ÍÄîÕÂÍÌÁËÏÂÈ¥£¬ËäÈ»Ó²ÁËÒ»µã¶ù£¬µ«ÊÇ»¹ÊÇÂú¿É¿ÚµÄ¡
$NÔö¼ÓÁËµÀĞĞÎåÄê£¬ÎäÑ§2000µã£¬Ç±ÄÜ500µã£¬¹ÙÖ°1µã£¬´¢Ğî10gold£¡£                           
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           



