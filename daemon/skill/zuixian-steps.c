// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ���������ƶˡ��������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ�С��������ӡ����ܹ���$N�Ĺ�����\n",
	"$nʹ����ǧ����������ǡ�ö����$N�Ĺ��ơ�\n"
       "����$n����Ʈ��,һ�С�Ц���쳾��,����һ�ݣ����ѱܿ���\n",
       "$nʹ�������¹�����,������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
       "$nһ�����������ʡ�,����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취���������²���\n");

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
		return notify_fail("������������������������������²���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
