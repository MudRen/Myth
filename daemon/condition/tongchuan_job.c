// tongchuan.c
// modify by mudring

#include <ansi.h>

int update_condition(object me, int duration)
{

    if (duration < 1)
    {
        if (me->query_temp("tongchuan"))
        {
            tell_object(me, HIY "������͢���£��ٸ���������ζȽ����ˣ�\n" NOR);
            if (me->query("office_number") > 0) me->add("office_number", -1);
        }
        me->apply_condition("job_busy", 1 + random(3));
        me->delete_temp("tongchuan");
        if (present("tongchuan ling", me))
            destruct(present("tongchuan ling", me));
        return 0;
    }

    if (present("tongchuan ling", me) && living(me)
        && !me->query_temp("tongchuan/kk") && random(10) > 3
        && interactive(me) && !environment(me)->query("no_pk"))
    {
        tell_object(me, HIY "��ͻȻ������Χɱ�����ǣ��о���ʲô����Ҫ�����ˣ�\n" NOR);
        me->add_busy(1);
        call_out("zuji", 1, me);    
    }

    me->apply_condition("tongchuan_job", duration - 1);
    return 1;
}

void zuji(object me)
{
    object ling;
    object obj;

    if (!me) return;
    ling = present("tongchuan ling", me);
    if (ling)
    {
        tell_object(me,"����Լ�о�������Χ�˹�������!!! \n");
        tell_object(me, RED "��⣡���Ʊ�������!\n" NOR);
        obj = new("/d/quest/xue/stealer");
        obj->move(environment(me));
        ling->move(obj);
        obj->do_copy(me);

        if (random(me->query("combat_exp")) >= 100000)
            call_out("killer_clone", 1, me);
    } else
        tell_object(me, "�����Ѿ���ɣ������ҵĶ����ɱ�ֵ�׷ɱ!\n");   
}

void killer_clone(object me)
{
    object obj;

    if (!me) return;
    tell_object(me, "��⣬�ֳ������˸��ˣ�\n");
    obj = new("/d/quest/xue/stealer");
    obj->move(environment(me));
    obj->do_copy(me);
}

string query_type(object me)
{
    return "job";
}
