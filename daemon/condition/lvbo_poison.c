#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   
         int l_temp;        
         me->set_temp("death_msg","�̲���¶���������ˡ�\n");
         if (random(4)>=3 ){
                 if( !living(me) )
                         message("vision", me->name() + "����һ����£��������[����]�졣\n", environment(me), me);
                 else{
                         tell_object(me, HIG "���Ȼ�е�����Ԫ�����㣬ͷ������ġ�\n" NOR );
                         message("vision", me->name() + "ͻȻ���ȷ������ֱ���һ�ţ����ֱ������\n",environment(me), me);
                 }
                 l_temp=50-(int)me->query_skill("force", 1)/20;
                 me->add("kee",-l_temp);
                 l_temp=60-(int)me->query_skill("force", 1)/20;
                 me->add("force",-l_temp);
                 if ((int)me->query_skill("force", 1)<180){ 
                         me->receive_wound("kee", random(30));
                         if( me->query("kee")<0)
                                 me->unconcious();
                         if( me->query("eff_kee")<0)
                                 me->die();
                 } 
         }
        if( duration !=1 ) 
         me->apply_condition("lvbo_poison", duration - 1);
        if( duration <= 1 ) return 0;
         return CND_CONTINUE;
}
