//yingzhaogong.c��ӥצ����
//not a main menpai skill(can be used by NPCs)

inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N����������ȫ�����һ���죡���ֳ�������צ������һ��ץ��$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		120,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N˫�������߳���������ڽڰθߣ������һ��ת�ۣ�˫צ����$n$lץ��",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N��צ��$n��ǰһ������צ���磬���¶�����$n��$l����һץ",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N�����أ�˫��һ��ʹ�˸���ӥ�����ա��Ʋ��ɵ�������$n",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"ֻ��$N���˼�����ͻȻһ���������ض��ɣ�˫צ�����쳣��ץ��$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		70,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N���һ����˫צ���͹��ǰ��һ�����ƺ�Ҫ��$n˺�÷�����Ƕ����",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��ǰһ�����ݣ�������$n���������һ����Ц����צ��$n��$l��ݺݵ�һץ",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$Nһ������������������۾��Ƶģ�һצ��һצ���಻����ץ��$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "ץ��"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("��ӥצ��������֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
