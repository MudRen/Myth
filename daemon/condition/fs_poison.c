#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{         
         tell_object(me, HIY "��ͻȻ����һ�ɶ���Ӹ������𣬲�����Ż������\n" NOR );
         tell_room(environment(me), HIY + me->name()+"���ϸ���һ��������Ų����ǣ�ͻȻ�³�һ�ѻ��\n" NOR,({ me }));               
         me->receive_wound("sen", 25);
         me->set_temp("death_msg","��ʬ���������ˡ�\n");     
         me->apply_condition("fs_poison", duration - 1);   
         if( duration < 1 ) return 0;   
         return CND_CONTINUE;
}
