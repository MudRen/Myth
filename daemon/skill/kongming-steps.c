//��ڤ����
//��ԯ��Ĺ�����Ṧ
//by ivy 2002.2.9

inherit SKILL;

string *dodge_msg = ({
        "$nһ�С��տ���Ҳ������Ӱ΢�������˿�ȥ��\n",
        "$n����һ�㣬һ�С�����׽Ӱ���ڿն��𣬱��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ����Ѩ���硹����������Ĵ�$Nͷ���ɹ���\n",
        "$n��Ӱ΢�����Ѿ���һ�С��չ�����������������\n",
        "ֻ��$n����һ����һ�С��չȴ���������$Nһ��������������Ʈ�˿�ȥ��\n",
        "$nһ�С���ǰ���󡹣���������ݳ����ߣ����˿�ȥ��\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 20 )
                return
notify_fail("�������������û�а취����ڤ������\n");

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
                return
notify_fail("�������������������������ڤ������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

