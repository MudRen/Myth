// baguazhen.c
//�������󷨡�weiqi... 980304
//can consider future development of ��.
//Ǭ�����������

inherit SKILL;

string *dodge_msg = ({
	"$n����һ�ˣ�̤�������Ǭ�ţ�ǡ�ɶ����$N��һ�С�\n",
	"����$n����һ�Σ�ͻȻ֮��ת�������ţ�������$N�����\n",
	"ֻ��$n���ż��������Կ����룬�����������ţ�����һ�����������š�$N֮���ƶ�ʱ��Ϊ���С�\n",
	"˵ʱ����ʱ�죬$n��ǧ��һ��֮�ʲ��˷�������������֮�У��ӹ���$N��һ�С�\n",
	"$n����һת�������Ҳ࿲��֮�У�ԶԶ�ض��˿�����\n",
	"$n������Ц������һ����ͷ������ţ����Ὣ���ƾ������⡣\n",
	"����$n����һ�ݣ���ʱû����Ӱ��$N����һ����ԭ��$n��㵽������֮�С�\n",
	"$n����б�ɣ���������֮�У����������ػ�����$N��һ�С�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취ѧ�����󷨡�\n");

	return 1;
}

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
