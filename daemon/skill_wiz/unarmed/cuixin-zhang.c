//cuixin-zhang.c �������ơ�weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N�������������ֻ��أ��������ĳʰ��죬����һ������֮������$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��������������λ��˫��һ������ͻȻ����������$n$lһ��һ��",
                "dodge":                -25,
                "parry":                -25,
	    "force":		70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ����һ������߳����������С�����ȴ����һ��֮�´����벻���ĽǶ�������$n��$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�ٺ�һЦ��˫���ڿ����л����������죡�����ݺ���ͻȻ�ɳ�һ�ƣ�������Ϣ������$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ���$n���������������ʱ��$N���ֱ۾���û����ͷ�Ƶ�����һ������������ػ�����$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����������ת�����������ݰ���$n��ȥ��תһȦ��һ�ƣ����Ʋ���$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$Nһ����Х����������ˮ�����������ƣ�������ת�����಻��������$n����Ҫ��",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ��ɨ���ȣ�˫��ȴ���������ϣ�����ֱ��ػ���$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("�������Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
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

