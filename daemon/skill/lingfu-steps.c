// ������ʽ

inherit SKILL;

// ���������ҹ����ӥ��������ľ�������ȷɣ���ȥ����

string *dodge_msg = ({
	"$n����һ����һ�С�ҹ����ӥ�������γ�������ȥ��\n",
	"$N��Ҫ����$n֮ʱ����Ȼֻ��$n�Լ�����������ȥ��\n"
	"��ʱ���Ѿ�������Ӱ��ԭ���Ǿ������С���ȥ���١���\n",
	"����$n�ƺ����Ѿ������ԣ���$N����֮ǰ�����ԡ������ȷɡ���Ծ��֮��\n",
	"$N�����������ƺ��԰�$n����һ�����ǡ�$nһҧ�������˷�����\n"
	"һ�С��������������Ȼ��Ч��������$N��\n",
	"$n����һ�����������ұ�ȥ��$N����׷����ֻ��$n�Ѿ�����Ծ����\n"
	"��һ�С�������ľ������$N�ֵ��Ǳ�������\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�����������������ѧϰ������ʽ�ľ��С�\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�����̫�ͣ�������ȥ̫Σ���ˣ�\n");
	if ((int)me->query("force") < 100)
		return notify_fail("����������㣬ǿ��������ʽ���߻���ħ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
