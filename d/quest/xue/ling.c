// ling.c
// ����
// by mudring

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIG"����"NOR, ({ "tongchuan ling", "ling pai", "ling", }));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long","��������������Ҫ�����õ����ͽ��\n");
        set("value", 0);
        set("material", "gold");
        set("no_drop",1);
        set("no_put",1);
        set("no_give",1);
    }
}

void init()
{
    add_action("do_send", "tongchuan");
    add_action("do_send", "chuanhuan");
    add_action("do_look", "kan");
    add_action("do_look", "chakan");
    call_out("dest", random(100)+600);
}

int do_look(string arg)
{
    object me = this_player();

    if (!arg) return 0;
    if ((arg=="ling pai" || arg=="ling" || arg=="tongchuan ling")
        && query("owner") == me
        && me->query_temp("tongchuan/get")
        && me->query_temp("tongchuan/name")
        && me->query_temp("tongchuan/id"))
    {
        tell_object(me, "��Ŀǰ��������Ҫȥ����" +
            me->query_temp("tongchuan/name") + "���\n");
        return 1;
    }
    else return 0;
}

int do_send(string arg)
{
    int i, k;
    object me, target;
    string msg;

    me = this_player();

    if (!arg) return notify_fail("��Ҫ����˭��\n");
    if (!objectp(target = present(arg, environment(me))))
        return notify_fail("������㣬��Ҫ�������˲������\n");

    if (userp(target))
        return notify_fail("�ٺ٣������ף��ǿ�Ҫ��û��ʦ��ʱ�򡣡���\n");

    if (!living(target))
        return notify_fail("������㣬���˿���˵����\n");

    message_vision("$N�ӻ����ͳ�һ�����\n",me);
        message_vision(HIY"$N�����ͽ������$n��ǰ˵����"
        "��ʦ����"+RANK_D->query_self(me)+"�������ٵ����ţ���Ҫ�����顣\n"NOR, me, target);

    if (!me->query_temp("tongchuan/get"))
    {
        message_vision(CYN"$N�������к��£����Ҵ������Σ�\n"NOR, target);
        return notify_fail("�Է��������Ĵ�����\n");
    }
    if (target->query("id") != me->query_temp("tongchuan/id")
        || target->query("name") != me->query_temp("tongchuan/name"))
    {
         message_vision(CYN"$N������ʦ�������������������Ҹ�ʲô��\n"NOR, target);
         return notify_fail("�Է��������Ĵ�����\n");
    }
    if (query("owner") != me)
    {
         message_vision(CYN"$N����������ʦ������ͽ�����Ǵ��Ķ������ģ�\n"NOR, target);
         this_object()->move(target);
         message_vision("$N�������е�����û���ˡ�\n", target);

         return 1;
    } else
    {
        message_vision(HIY "$N˫����������˵������λ"+RANK_D->query_respect(me)
            +"������һ���������͵���\n"NOR, target, me);
/*
        target->command("job " + me->query("name") +
            "����ּ����" + target->query("name") + "���");
*/
    }

    i = me->query("office_number");
    if (i < 800 )
    {
        i = 800 + random(100) + i / 10;
    } else
    {
        i = 1000 + random(200) + i / 14;
        if (i > 1500) i = 1500 + random(200);
    }

    k = me->query_temp("tongchuan/kk");
        me->set("menpai_task",99);
    if (k > 3) k = 3;
    if (!k)
        i = i / 20;
    else
        i = i * k / 4;
/*
    if (me->query("combat_exp") > 10000000)
        i = i / 3 * 5;
*/
    me->add("combat_exp", i);
    me->add("daoxing", i);
    me->add("potential",i/8);
    me->add("office_number", 1);
    me->add("weiwang", 1); 
    tell_object(me, HIW"�ڴ˴��ж��У���������"+chinese_number(i)+
        "����ѧ"+chinese_daoxing(i)+"�����Լ�"+chinese_number(i/8)+"��Ǳ�ܡ�\n"NOR);
    tell_object(me, HIW"Ϊ���ų�������Ĺ�ְ�����������ˡ�\n"NOR);

    msg = " do tongchuan got " + i + " exp " + i/8 +" pot ";
    MONITOR_D->report_debug_object_msg(me, msg);
    MONITOR_D->mudring_log("tcjob", me, msg);

    me->delete_temp("tongchuan");
    me->clear_condition("tongchuan_job");
    if (me->query("combat_exp") < 10000)
        me->apply_condition("job_busy", 5);
    else
        me->apply_condition("job_busy", 5 + random(5));

    this_object()->move(get_object("/obj/empty"));
    call_out("dest", 2);
    return 1;
}

void dest()
{
    object ob = this_object();

    if (ob)
    {
        message_vision("$N��Ȼ������·�ϲ����ˡ�\n", ob);
        destruct(ob);
    }
}


