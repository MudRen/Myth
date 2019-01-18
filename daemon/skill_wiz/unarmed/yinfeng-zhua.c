// yinfeng-zhua.c, ������צ��
// created 9-5-97 pickle
//menpai skill(can be used by some yaomo NPCs)

//  ù���˱ǣ�ǧ���ٿף���ȱ��ȫ��ҡҡ��׹

inherit SKILL;

mapping *action = ({
  ([
    "name":		"��ù���˱ǡ�",
    "action":
"$nֻ����������һ��ù��������ּ䣬$N����צ�ѵ�$l",
    "force":		50,
    "dodge":		-10,
    "parry":		-10,
    "damage_type":	"ץ��",
  ]),
  ([
    "name":		"��ǧ���ٿס�",
    "action":
"$N��׾�ޱȵ���צ��$n��$lץȥ�����п���ǧ���ٿף�\n"
"��������������$n�м�ʱ��ȴ���Ƶ���æ���ң��п಻��",
    "force":		100,
    "dodge":		10,
    "parry":		-10,
    "damage_type":	"ץ��",
  ]),
  ([
    "name":		"����ȱ��ȫ��",
    "action":
"$N��צ��������צѸ���ޱȵ���$n��ʩ��ץ����$nȫ���ע�ضԸ�\n"
"����ץʱ��$N����צ����֪�����ص���$n��$l",
    "force":		70,
    "dodge":		10,
    "parry":		10,
    "damage_type":	"ץ��",
  ]),
  ([
    "name":		"��ҡҡ��׹��",
    "action":
"$NͻȻ��Ծ�����ߣ��Ӹ�������$nץ����$n��Ȼ����\n"
"$N�ظ�����Ŵ󿪣�ȴ���⡸ҡҡ��׹�����������ƱƵû����Ծ�",
    "force":		70,
    "dodge":		-10,
    "parry":		10,
    "damage_type":	"ץ��",
  ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������צ������֡�\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if (me->query("class") != "yaomo")
		return notify_fail("����ûצ�ӣ���ô������צ��\n");
	if( (int)me->query("sen") < 40)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
