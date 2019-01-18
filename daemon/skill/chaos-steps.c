// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
	"$nʹ������ת��Ȩ�����������ɵ�������\n",
	"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
	"����$nһ�С��������١�ʹ���������Ƶ�$N���\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취���������ǲ���\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("������������������������������ǲ�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
