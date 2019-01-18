#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{         
         tell_object(me, HIR "ÄãÖ»¾õµÃÆøÑª·­Ó¿£¬»ëÉíÓÌÈçÇ§ÍòÖ§¶¾ÖëÔÚÒ§àÍ£¬Í´¿àÄÑÈÌ£¡\n" NOR );
         tell_room(environment(me), HIR + me->name()+"Ãæ¿×Å¤Çú£¬ÍäÏÂÑü²»×¡µÍºß£¬»ëÉí²»Í£µÄ²ü¶¶£¡\n" NOR,({ me }));             
         me->receive_wound("kee", random(150)*(1+random(3)));      
         me->receive_wound("sen", random(100)*(1+random(3)));               
         me->set_temp("death_msg","ÖÐÇ§Öë¶¾ËÀÁË¡£\n");     
         me->apply_condition("qzhu_poison", duration - 1);   
         if( duration < 1 ) return 0;   
         return CND_CONTINUE;
}

string query_type(object me)
{
         return "poison";
}
