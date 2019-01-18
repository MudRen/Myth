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
"$Nһ��$w��ѣ�ֻ��һ������������$w��������һ������$n��$l",
                "dodge":                0,
		"parry":	-20,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����$wһ����ʹ��һ�С�������¡���$w����ɭɭ��������$n$l",
                "dodge":                0,
		"parry":	0,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N���е�$w������һ��һ��������$n΢һ����֮ʱ��$w�ѻ���һ�������Ļ�������$n$l",
                "dodge":                5,
		"parry":	-15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����һת������$w����һ�ϣ������⽫��δ��֮�ʣ�$wһ��ת�ۺ�����һ����$n��ͷ����",
                "dodge":                5,
		"parry":	-5,
                "damage":               30,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "",
                "action":
"$N�ֽ�һ����$wһ�����������転�س�$n���˹�ȥ������$w���Ʋ����·���ʵ�򰵲�����",
                "dodge":                0,
		"parry":	-15,
                "damage":               35,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "",
                "action":
"$Nһ��$w��ʹ�˸����ºڷ�ߡ������е�$w����׷��Ķ��һ��������$n��$l",
                "dodge":                0,
		"parry":	-15,
                "damage":               35,
                "damage_type":  "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취ѧ������������������������ɡ�\n");

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "fork" )
                return notify_fail("���������һ���ֲ����ѧ��������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="fork";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("�����������������û�а취��ϰ��������\n");

	if(!environment(me)->query("cold"))
		return notify_fail("�˵ز������䣬�����к����档\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/yueya-chan/" + func;
}

