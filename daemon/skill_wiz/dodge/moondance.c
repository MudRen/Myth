//�����������衿 moondance.c
// cglaem...12/07/96.

inherit SKILL;

string *dodge_msg = ({
     "$n��ͷϸ��ȹ�ޣ���˼��������������֮���ƺ�����������ȴ��$N����һһ�������Ρ�\n",
     "ֻ��$nһ��ת����Ȼ����һЦ��$Nһ��֮�£����ﻹ�����ڡ�\n",
     "����$n���һЦ�����˷��������ξ���$NƮ����\n$Nֻ��һ��������ǣ���һ�о�������֮����\n",
     "$n�����飬��֫��š����Ȼ�ó��߲���Ӱ��$N��һ��������ֵó����ˣ���Ӱ��\n",
     "$nȹ��ƮƮ�������橣���Ȼ��$Nͷ���ɹ������Ů�����֮�ˣ��������֮�Σ�$N���ɵÿ����ˣ�\n",
     "$n�Ų���ӯ��������Ȼ�����ӱ�����ˮ����Ʈ��һ���ӹ�������$N����Ϯ��������Ȼ��ȥ��\n",
     "$n����΢����������磬���Ὣ$N�ľ�������һ�ԣ��������⡣\n",

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("����������ֻ��Ů�Բ�������\n");
	if( (int)me->query("spi") < 10 )
		return notify_fail("������Բ�����û�а취�����������衣\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ���̫���ˣ����������������衣\n");
	me->receive_damage("sen", 30);
	return 1;
}
