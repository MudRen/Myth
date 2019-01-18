// flower_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        int damage_kee=10, damage_sen=10;

        if(me->query("max_kee")>200)
                damage_kee=me->query("max_kee")/20;
        if(me->query("max_sen")>200)
                damage_sen=me->query("max_sen")/20;
        if(damage_kee > 60) damage_kee = 60;
        if(damage_sen > 5) damage_sen = 5;
                                                        
        me->receive_wound("sen", damage_sen);
        me->receive_wound("kee", damage_kee);
        me->set_temp("death_msg","�������������ˡ�\n");
        me->apply_condition("flower", duration - 1);

        if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
                message_vision(HIG"$N����¶����ֵ�Ц�ݣ�ͷ��˿˿����ð����\n"NOR, me);
        else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
                message_vision(HIY"$N���Ϸ���ŨŨ���㣬�����ĳ�������\n"NOR, me);            
        else 
                message_vision(HIM"$N���˸����磬ԭ�����˺���֮����\n"NOR, me);
                
        if( duration < 1 ) return 0;
        return 1;
}
