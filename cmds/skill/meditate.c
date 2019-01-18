// meditate.c
// modify by mudring Jan/03/2003

#include <skill.h>

int meditating(object me);
int halt_meditate(object me);
int main(object me, string arg)
{
    string mana;
    mapping msg;
    int meditate_cost, max;
    object where;

    seteuid(getuid());

    where = environment(me);
        
    if (!arg || !sscanf(arg, "%d", meditate_cost))
        return notify_fail("��Ҫ�����پ���ڤ˼��\n");

    if (meditate_cost <= 0 && me->query_temp("pending/meditate"))
    {
        return halt_meditate(me);
    }

    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
        return notify_fail("ս���в���ڤ˼�����߻���ħ��\n");

    if (where->query("no_fight"))
        return notify_fail("���ﲻ�����������ĵط���\n");

    if (me->query_condition("no_mana"))
         return notify_fail("��е��������Ժ����޷�ڤ˼��\n");
              
    if (!(mana = me->query_skill_mapped("spells")))
        return notify_fail("��������� enable ѡ����Ҫ�õķ�����\n");

    if (me->query("food") < 40 || me->query("water") < 40)
        return notify_fail("��̫�����ˣ�ʵ��������ʹ��������\n");

    if (meditate_cost < 20)
        return notify_fail("������Ҫ�� 20 �㡸���񡹲���ڤ˼��\n");

    if ((int)me->query("sen") < meditate_cost)
        return notify_fail("���������ǲ���,����������Ƿ��ˡ�\n");

    msg = SKILL_D(mana)->meditate_msg(me);
    if (!msg || undefinedp(msg["start_my_msg"]))
        write("����ϥ����������ڤ˼��һ�����\n");
    else
        write(msg["start_my_msg"]);

    me->set_temp("pending/meditate", 1);
    me->set_temp("meditate_cost", meditate_cost);

/*
    if (!msg || undefinedp(msg["start_other_msg"]))
        tell_room(environment(me),
                  me->name() + "��ϥ����������ڤ˼��һ�����\n", ({ me }));
    else
        tell_room(environment(me),
                  msg["start_other_msg"], ({ me }));
*/

    me->start_busy((: meditating :), (:halt_meditate:));
    return 1;
}

int meditating(object me)
{
    string mana;
    mapping msg;

    int meditate_cost = (int)me->query_temp("meditate_cost");
    int mana_gain     = (int)me->query_skill("spells",1) / 10
                        + (int)me->query_spi() / 3 + random(3);

    int max = me->query_max_mana();

//    if (mana_gain > meditate_cost) mana_gain = meditate_cost;
    if (mana_gain < 5) mana_gain = 20;
    if (mana_gain > 25) mana_gain = 100;
    mana_gain = 100;
    mana_gain*=2;

    me->receive_damage("sen", 20);
    me->add("mana", mana_gain);
    me->set_temp("meditate_cost", meditate_cost -= 20);

    if (me->query("mana") > me->query("max_mana") * 2)
    {
        if (me->query("max_mana") >= max)
        {
            tell_object(me, "����ķ������ӵ�˲�����Ȼ��������һƬ���ң�"
                        "�ƺ������������Ѿ�����ƿ����\n");
        } else
        {
            me->set("mana", me->add("max_mana", 1));
            tell_object(me, "��ķ�����ǿ�ˣ�\n");
 
            if (me->query("max_mana") > me->query("maximum_mana"))
                me->set("maximum_mana", me->query("max_mana"));
        }
        me->set("mana", me->query("max_mana"));
        return halt_meditate(me);
    }

    mana = me->query_skill_mapped("spells");
    if (mana) msg = SKILL_D(mana)->meditate_msg(me);
    if (meditate_cost > 0)
    {
        if (msg && !undefinedp(msg["exec_my_msg"]))
            tell_object(me, msg["exec_my_msg"]);
        if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
            tell_room(environment(me), msg["exec_other_msg"], ({me}));
        return 1;
    }

    me->delete_temp("pending/meditate");
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "���й���ϣ���ڤ˼�лع�������\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"�й���ϣ���ڤ˼�лع�������\n", ({me}));
    else
        tell_room(environment(me),
                  msg["end_other_msg"], ({me}));
*/
    me->start_busy(1);
    return 0;
}

int halt_meditate(object me)
{
    string mana;
    mapping msg;

    if (me->query("mana") > me->query("max_mana") * 2)
        me->set("mana", me->query("max_mana") * 2);
    me->delete_temp("pending/meditate");
    mana = me->query_skill_mapped("spells");
    if (mana) msg = SKILL_D(mana)->meditate_msg(me);
    if (!msg || undefinedp(msg["end_my_msg"]))
        tell_object(me, "���й���ϣ���ڤ˼�лع�������\n");
    else
        tell_object(me, msg["end_my_msg"]);
/*
    if (!msg || undefinedp(msg["end_other_msg"]))
        tell_room(environment(me),
                  me->name()+"�й���ϣ���ڤ˼�лع�������\n", ({me}));
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
ָ���ʽ : meditate|mingsi [<�ķѡ��񡹵�����Ԥ��ֵ 30>]
           meditate|mingsi 0 ��ֹͣڤ˼
 
����ڤ˼��������ľ�������Ч�ؼ������۳��ܹ�����ʩչ����������
�����������Լ��ķ�����

HELP
        );
        return 1;
}
