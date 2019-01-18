#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
         if( !living(me) ) return CND_CONTINUE;      
         tell_object(me, HIB "���Ȼ�е����彩ֱ���Ѿ�����ʹ���ˡ�\n" NOR );            
         me->receive_wound("kee", 50);
         if(userp(me))
                 me->receive_wound("sen", 60);
         else me->receive_wound("sen", 80);        
         me->set_temp("death_msg","���ڹ���֮���������ˡ�\n");
      
         if( me->query("sen") > 301)
                 tell_room(environment(me), YEL+me->name()+"ͻȻֻϥ�����������������£����з����������޵ĺɺ�֮����\n" NOR, ({ me }));            
         else if( me->query("sen") < 450 && me->query("sen") > 301)
                 tell_room(environment(me), BLU+me->name()+"��Ȼ����ѻ�������Ц�����Եù������ס�\n" NOR,  ({ me }));        
         else if( me->query("sen") < 300 && me->query("sen") > 201)
                 tell_room(environment(me), HIB+me->name()+"��ʱ���Ǹ��Ӻ�Ϳ��ָ���������ҡ���ҧ��\n" NOR,({ me }));           
         else    
                 tell_room(environment(me), HIR+me->name()+"ͻȻ����һ�ţ����ڵ��ϲ�ͣ�ط�����\n" NOR,({ me }));

         if( duration < 1 ) return 0;           
         me->apply_condition("bt_poison", duration - 1);
         return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
