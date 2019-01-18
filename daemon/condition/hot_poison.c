#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
         if( !living(me) ) {
                 message("vision", me->name() + "ȫ���ڣ�ɢ����һ�󽹺�ζ��\n", environment(me), me);
         }
         else {
                 tell_object(me, HIR "��Ȼһ�ɻ���֮��Ϯ�����̵����ֽŷ�����\n" NOR );
                 tell_room(environment(me), HIR + me->name()+"ͻȻȫ��ð��������̣��촽���ѣ�˫�ֺ��ҵػ����š�\n" NOR,({ me }));      
         }
         me->receive_damage("kee", 25);
         if(userp(me))
                 me->receive_wound("sen", 20);
         else me->receive_wound("sen", 40);
         me->apply_condition("hot_poison", duration - 1);
         if( duration < 1 ) return 0;
         return CND_CONTINUE;
}

string query_type(object me)
{
         return "poison";
}
