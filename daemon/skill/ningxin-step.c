//�����Ĳ����� ningxin.c
inherit SKILL;

string *dodge_msg = ({
        "����$n������ӯ����$N������Ử����\n",
            "ֻ��$n����һ�ˣ��������֮�У�$N��һ�ж�ʱû��Ŀ�ꡣ\n",
            "$nһת������ϸ��ͻ����������$N�Ĺ��ơ�\n",
            "$n��������ڵ���һ�㣬��С������Ʈ�ڰ�գ��ܿ���$N�Ĺ��ơ�\n",
            "$n�ƺ��е�����������ۿ���Ҫ���С�����$N��ǰ�ٻ��뽵����֪���ľ��˿��ˡ�\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if (me->query("class") != "youning")
                return notify_fail("���������֮�����������Ĳ�����\n");
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�����������������������ϰ���Ĳ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
