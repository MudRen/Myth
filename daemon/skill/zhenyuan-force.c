// zhenyuan-force.c  ����Ԫ�񹦡�
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{
        if( (int)me->query_skill("force", 1) < 10 )
//              || (int)me->query_skill("force", 1) <= (int)me->query_skill("zhenyuan-force", 1) )
                return notify_fail("����ڹ���Ϊ����������޷�ѧϰ��Ԫ�񹦡�\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ԫ��ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("zhenyuan") + "/zhenyuan-force/" + func;
}

