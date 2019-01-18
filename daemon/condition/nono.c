// pk_counter.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        object env=environment(me);
        int damage_kee=100,damage_sen=100;
        string str = "";
        if (duration<1) return 0;
        if(env) {
// if (random(7) > 5)
str = "��"+ env->query("short") + "һ������";
MONITOR_D->report_rumor_object_msg(me, str + "��");
            if(env->query("no_fight")&& env->query("no_magic"))
              {
                me->receive_wound("sen", damage_sen);
                me->receive_wound("kee", damage_kee);
                message_vision("���ϳ���һ�����磬��������������������$N��ͷ�ϡ�\n", me);
                me->set_temp("death_msg","�����������ˡ�\n");
                me->apply_condition("no_pk_time", duration);
              }
                    
            else 
            me->apply_condition("no_pk_time", duration-1);
            
        }



        if( duration < 1 ) return 0;

        return CND_CONTINUE;
}
