// baohu_job.c
// by mudring

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    object killer;
    object env = environment(me);
    string target = me->query_temp("dajiu/id");

    if (duration < 1)
    {
        if (me->query_temp("dajiu/get"))
        {
            me->delete_temp("dajiu");
            tell_object(me, HIY"����ж�ʧ���ˣ�\n"NOR);
            me->apply_condition("job_busy", 10 + random(5));
            if (me->query("dajiunpc") > 0) 
                me->add("dajiunpc", -1);
        }
        return 0;
    }

    if (env)
    {
        if (target && present(target, env) &&
// 28              MISC_D->find_place(me) == me->query_temp("dajiu/where") &&
            random(me->query_kar()) < 22 &&
            interactive(me) &&
            me->query_temp("dajiu/get") &&
            me->query_temp("dajiu/kk") != 1)
        {
            if (objectp(killer = new("/d/quest/dajiu/guai")))
            {
                tell_object(me, RED "���Ȼ�о�����ɱ�����ǣ�\n" NOR);
                killer->do_copy(me);
            }
        }
    }

    me->apply_condition("baohu_job", duration - 1);
    return CND_CONTINUE;
}
string query_type(object me) {return "job";}
