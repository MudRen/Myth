//Cracked by Roath

//Ansi 99.8
inherit FORCE;
string type() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ϼ�񹦡�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ϼ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("shushan") + "/zixia-shengong/" + func;
}

