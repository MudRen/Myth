//��ȸ�����ķ�
//���Ұ�����ڹ�
//by junhyun 2002.4.20
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ( me->query_skill("moonforce",1)     
                || me->query_skill("ningxie-force",1)
                || me->query_skill("lengquan-force",1)
                || me->query_skill("zhenyuan-force",1)
                || me->query_skill("huntian-qigong",1)
                || me->query_skill("tonsillit",1)
                || me->query_skill("dragonforce",1)
                || me->query_skill("huomoforce",1)
                || me->query_skill("wuxiangforce",1)
                || me->query_skill("lotusforce",1)
                || me->query_skill("zixia-shengong",1))
                return notify_fail("����ɢ�˱����ڹ���ѧ�����ķ��ɣ���������߻���ħ�ģ�\n");
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����ķ���\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("gaoye") + "/kongque-force/" + func;
}

