// longma-steps.c by angell

inherit SKILL;

string *dodge_msg = ({
        "$nһ�С���Ծ��Ϫ�����аεض��𣬱��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ���׾Թ�϶�����ѱ����߳�֮�⡣\n",
        "$nʹ������Ծ��Ԩ���������˼��£����˿�ȥ��\n",
        "$n����һ�㣬һ�С�Ǳ����Ԩ���ڿն��𣬱ܹ�����һ����\n",
        "����$nʹһ�С���ʧǰ�㡹����ϥ�򵹣��������Ķ��˹�ȥ��\n",
        "$n��Ӱ΢�����Ѿ���һ�С��������ס�����������\n",
        "����$nһ�С�������Ծ��ʹ�����������Ѳ�����\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����������\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�������������������������������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
