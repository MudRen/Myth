//zuixiansteps.c �������²�
//DHXY-EVIL       2000.7.6
inherit SKILL;

string *dodge_msg = ({
"$n��Ȼ��������һ������ھ��������ɸ���һ���������$N��һ�С�\n",
"$n�������ʣ��ҽ�һ��˳�Ƶ���$N�Ļ��$N����������һ��ȫ����ա�\n",
"$n˫�������Ʊգ�˳��$N����ʽһ���ٱ����ƣ�ȫ����ϥ�����ƽƽ������ȥ��\n",
"����$n�������Ƶ��������һ�����ҽ�ȴֱ�߶��ϣ���$N���˿�ȥ��\n",
"$n˫������������һ�������ڵأ����ζ�ʱ����أ��պñƹ���$N����ʽ��\n",
"����$nҡҡ�ڰڵ������˼��������²�������ȴ�Ѿ�ת����$N�����\n",
"ȴ��$n��Ų����Լ��ҽ���һ�裬����������ȥ�����ɶ����$N�Ĺ�����\n",
"$n�������࣬�Ų�����һ̤���о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("�����ڽ����鸡������Ϣһ��ɡ�\n");
	if((int)me->query("force") < 3 )
		return notify_fail("�������������������Լ�������ȥ�ˡ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
