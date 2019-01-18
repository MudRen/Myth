//���ֻ��ȡ�lunhui-zhang.c
inherit SKILL;

/*
�ֻ���    dodge  5    parry  -10    damage  25
���ſ����书����������ɱֹɱ���ȳ����ͣ�ɱ�˲�����
*/

mapping *action = ({
        ([      "name":                 "��Ӧ��ˬ",
                "action":
"$N������ţ���ɫׯ�ϣ�һ�С���Ӧ��ˬ������$w����ֱ�룬�ɴ�$n$l",
                "dodge":                -10,
		"parry":               -5,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���޽���",
                "action":
"$N����$wһ����ʹ�������޽�����������һ����Ӱ����ԼԼ���������޵���$nѹ��",
                "dodge":                15,
		 "parry":               -15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ͷ�ǰ�",
                "action":
"ֻ��$N����$w���ᣬ���ص�������С���ͷ�ǰ�������Ʈ�ݣ�\n$n�ۼ��ȷ�Ϯ��������֪����Ǻ�",
                "dodge":                20,
		"parry":               -20,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ڽ�����",
                "action":
"$N���һ��������$w��$n��ͷ���䣬����δ�����ѽ�$n������·��������һ�С��ڽ����ӡ�",
                "dodge":                -5,
		"parry":               0,
                "damage":               30,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�����ֻ�",
                "action":
"$N����$w������һ�ݣ�һ�С������ֻ֡���$n���벻���ĵط��̳���$n��ʱ�����޴룬�Ǳ����",
                "dodge":                -10,
		"parry":               -5,
                "damage":               15,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ٶ��ֻ�",
                "action":
"$N����ͻ��ɷ������������$w������$n$l���䣬���С��ٶ��ֻء������ֿ��ֺ�",
                "dodge":                20,
		"parry":               -15,
                "damage":               35,
                "damage_type":  "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취ѧ�ֻ��ȣ�����������������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("���������һ�����Ȳ���ѧ�ֻ��ȡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return
notify_fail("�����������������û�а취��ϰ�ֻ��ȡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���ֻ��ȡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/lunhui-zhang/" + func;
}

