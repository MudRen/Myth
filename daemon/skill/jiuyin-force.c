//��������澭
//��ԯ��Ĺ�����ڹ�
//by ivy 2002.2.9
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
/*
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
                return notify_fail("����ɢ�˱����ڹ���ѧ��������澭�ɣ���������߻���ħ�ģ�\n");
*/
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����ľ���\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������澭ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("gumu") + "/jiuyin-force/" + func;
}

