#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{         
         tell_object(me, MAG "��ͻȻ����΢΢ͷ�Σ������������޷���������Ϣ��\n" NOR );
         tell_room(environment(me), HIB + me->name()+"��ɫ�԰ף��������ң����µ���ײײ��\n" NOR,({ me }));             
         me->receive_damage("kee", 25);      
         me->receive_wound("sen", 25);         
         me->set_temp("death_msg","����٢�޻������ˡ�\n");      
         me->apply_condition("man_poison", duration - 1);   
         if( duration < 1 ) return 0;   
         return CND_CONTINUE;
}
