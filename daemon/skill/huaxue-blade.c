//����������yueya-chan.c 
inherit SKILL;

/*
��������    dodge  5    parry  -10    damage  25
��������ʹ��������Ϊ���գ������ڻ��Ƶ��ַ�����ȱ����
�����쳣��
*/

mapping *action = ({
        ([      "name":                 "",
                "action":
"$Nб���������ϣ�����$wӭ��һ�Σ����������$n�ĺ���",
                "dodge":                0,
		"parry":		-20,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����һ��������$w������ߣ�������Ϣ������$n��˫��",
                "dodge":                -10,
		"parry":		0,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N˫��һ��$wͻ��Ѫ�⣬��������������һ��������$n��ȥ",
                "dodge":                5,
		"parry":		-15,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����ͻȻ��������������$wЮ��һ��Ѫ������$n��$l",
                "dodge":                5,
		"parry":	-5,
                "damage":               30,
                "damage_type":  "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;
	int a,b;
	a=(int)me->query_skill("huaxue-force", 1);
	b=(int)me->query_skill("huaxue-blade", 1);

	if( a < b )
		return notify_fail("��Ļ�Ѫ�񹦲�����������������ɡ�\n");

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�����ѧ��Ѫ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="blade";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int a,b;
	a=(int)me->query_skill("huaxue-force",1);
	b=(int)me->query_skill("huaxue-blade",1);
	if( a < b )
		return notify_fail("��Ļ�Ѫ�񹦲�������������������ɡ�\n");

        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("�����������������û�а취��ϰ��Ѫ������\n");

	if(!environment(me)->query("cold"))
		return notify_fail("�˵ز������䣬�����к����档\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�黯Ѫ������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/bibotan/huaxue-blade/" + func;
}

