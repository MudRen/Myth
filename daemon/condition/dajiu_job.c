// dajiu_job.c
// by mudring

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    if (duration < 1)
    {
        if (me->query_temp("baohu/get"))
        {
            me->delete_temp("baohu");
            tell_object(me, HIY"�㱣������ʧ���ˣ�\n"NOR);
            me->apply_condition("job_busy", 10 + random(5));
            if (me->query("baohuhuaxian") > 0) 
                me->add("baohuhuaxian", -1);
        }
        return 0;
    }


    me->apply_condition("dajiu_job", duration - 1);
    return CND_CONTINUE;
}
string query_type(object me) {return "job";}
