//Ħ����


inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ�С���벶��ʽ��������ץ��$n�ĵ������$n�����Է���һ˲�䣬����ȴ��������$n��$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action": "$N˫��һ��������÷����䡹��˫���紩������һ�����·��ɡ�\n$n�������ۣ�ɲ�Ǽ�$N����������ǰ",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([	"action":		"ֻ��$Nһת��һָ��в�´���������$n��$l��ȴ����һ�С��������ߡ�",
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N˫��һ������������ƶ�������һ�С���ʿ��ɽ������һ�������$n��$l",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"����",
                        "weapon":		"����", 
	]),
            ([	"action":		"$Nһ�С������������������ڿ����黮�˸��뻡������$n��$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
            ([	"action":		"����$Nһ��ŭ�����ָ߸߾���һʽ��������ɽ��������$n��$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([  "action": 	"$N˫��һ��������ͻ�����֮�⣬����һ�������������ɫ�������������$n",
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "����",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��Ħ���ֱ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("moyunshou_per");
        if( !me->query_temp("moyunshou_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰĦ���֡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ��Ħ���֡�\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/moyun-shou/" + func;
}

