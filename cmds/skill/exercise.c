// exercise.c
// modify by mudring Jan/03/2003

#include <skill.h>

int exercising(object me);
int halt_exercise(object me);

int main(object me, string arg)
{
    string force;
    mapping msg;
    int exercise_cost, max;
    object where;

    seteuid(getuid());

    where = environment(me);
        
    if (!arg || !sscanf(arg, "%d", exercise_cost))
        return notify_fail("��Ҫ��������������\n");

    if (exercise_cost <= 0 && me->query_temp("pending/exercise"))
    {
        return halt_exercise(me);
    }

    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
        return notify_fail("ս���в������ڹ������߻���ħ��\n");

    if (where->query("no_fight"))
        return notify_fail("��ȫ���ڽ�ֹ������\n");

    if (me->query_condition("no_force"))
         return notify_fail("��е�������Ϣ�Ҵܣ��޷�����������\n");
                
    if (!(force = me->query_skill_mapped("force")))
        return notify_fail("��������� enable ѡ����Ҫ�õ������ڹ���\n");

    if (me->query("food") < 40 || me->query("water") < 40)
        return notify_fail("��̫�����ˣ�ʵ��������ʹ��������\n");

    if (exercise_cost < 20)
        return notify_fail("������Ҫ�� 20 �㡸��������������\n");

    if ((int)me->query("kee") < exercise_cost)
        return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

    msg = SKILL_D(force)->exercise_msg(me);
    if (!msg || undefinedp(msg["start_my_msg"]))
        write("�������������ù���һ����Ϣ��ʼ������������\n");
    else
        write(msg["start_my_msg"]);

    me->set_temp("pending/exercise", 1);
    me->set_temp("exercise_cost", exercise_cost);

/*
    if (!msg || undefinedp(msg["start_other_msg"]))
        tell_room(environment(me),
                  me->name() + "��ϥ���£���ʼ�˹�������\n", ({ me }));
    else
        tell_room(environment(me),
                  msg["start_other_msg"], ({ me }));
*/

    me->start_busy((: exercising :), (:halt_exercise:));
    return 1;
}

int exercising(object me)
{
    string force;
    mapping msg;

    int exercise_cost = (int)me->query_temp("exercise_cost");
    int force_gain = (int)me->query_skill("force",1)/10
               +(int)me->query_con()/3 + random(3);

    int max = me->query_max_force();

//    if (force_gain > exercise_cost) force_gain = exercise_cost;
    if (force_gain < 5) force_gain = 20;
    if (force_gain > 25) force_gain = 100;
    force_gain = 100;
    force_gain*=2;

    me->receive_damage("kee", 20);
    me->add("force", force_gain);
    me->set_temp("exercise_cost", exercise_cost -= 20);

    if (me->query("force") > me->query("max_force") * 2)
    {
        if (me->query("max_force") >= max)
        {
            tell_object(me, "�������Ϣ�鲼ȫ����ʱȴû�й��������ļ���"
                        "�ƺ�������Ϊ�Ѿ�������ƿ����\n");
        } else
        {
            me->set("force", me->add("max_force", 1));
            tell_object(me, "���������ǿ�ˣ�\n");
 
            if (me->query("max_force") > me->query("maximum_force"))
                me->set("maximum_force", me->query("max_force"));
        }
        me->set("force", me->query("max_force"));
        return halt_exercise(me);
    }

    force = me->query_skill_mapped("force");
    if (force) msg = SKILL_D(force)->exercise_msg(me);
    if (exercise_cost > 0)
    {
        if (msg && !undefinedp(msg["exec_my_msg"]))
            tell_object(me, msg["exec_my_msg"]);
        if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
            tell_room(environment(me), msg["exec_other_msg"], ({me}));
        return 1;
    }

    me->delete_temp("pending/exercise");
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "���й���ϣ���һ����������վ��������\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"�й���ϣ���һ����������վ��������\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 0;
}

int halt_exercise(object me)
{
    string force;
    mapping msg;

    if (me->query("force") > me->query("max_force") * 2)
        me->set("force", me->query("max_force") * 2);
    me->delete_temp("pending/exercise");
    force = me->query_skill_mapped("force");
    if (force) msg = SKILL_D(force)->exercise_msg(me);
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "���й���ϣ���һ����������վ��������\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"�й���ϣ���һ����������վ��������\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 1;
}

void remove()
{
    object *obs = users();
    foreach (object ob in obs)
    {
        if (ob->query_temp("pending"))
        {
            ob->start_busy(1, 2);
            ob->interrupt_me();
            ob->start_busy(1);
        }
    }
}


int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������>]
           exercise|dazuo 0 ��ֹͣ����

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

��ο� help stats
HELP
        );
        return 1;
}

