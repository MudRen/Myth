//������


inherit SKILL;

mapping *action = ({
	([	"action":		"$N���ֺ�ʮ��һʽ������������˫ȭ���ƶ���������$n��$l",
		"dodge":		-10,
		"parry":		10,
		"force":		100,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N�ڿշ���һʽ����ָɽ��������$n����ǰ���",
		"dodge":		-20,
		"parry":		-20,
		"force":		140,
		"damage_type":	"����",
                        "weapon":		"����", 
	]),
            ([	"action":		"$Nһʽ�������ɡ�������ʮָ���$n��ȫ����ʮ����ҪѨ",
		"dodge":		30,
		"parry":		-10,
		"force":		200,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
            ([	"action":		"$N��Ŀ���ӣ�˫��������һʽ����������������˷������������ǵ�����",
		"dodge":		10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([  "action": 	"$N��Ц��Ц��˫ȭ�����޶���һʽ������Ц������Ȼ����$n��ǰ��",
                "dodge":                -50,
                "parry":                -50,
                "force":                120,
                "damage_type":  "����",
	 ]),
});

int valid_learn(object me)
{
        if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("�����ֱ�����Ͼ����ľ���������\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������ֱ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("lanhuashou_per");
        if( !me->query_temp("lanhuashou_per") ) {
        return action[random(5)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{

        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�����֡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ�������֡�\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("pansi") + "/lanhuashou/" + func;
}

