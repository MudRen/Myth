//�廢���ŵ�, wuhu-blade.c
//modified 4-17-97 pickle

/*
�廢���ŵ�    dodge  0    parry  0    damage  20
�����г���֮���򣬵����ʹ�û��ң������洫����ʵ
���Ź������൱ʵ�õġ�
*/

// ���ٻ���������ƽ�����ﻢ����
// ������ʳ�����˳ɻ�

inherit SKILL;

mapping *action = ({
        ([      "name":                 "������ʳ",
                "action":
"$N����Ծ�ڿ��У����������ʳһ�㣬����$w��������֮�ƣ���$n��ͷ����",
                "dodge":		0,
		"parry":		0,
                "damage":		15,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���˳ɻ�",
                "action":
"$Nչ���Ṧ��$n��Χ�ɱ�����������$n��ȥ������\n"
"$nֻ��������Ӱ����������ͬ�ķ����������ɾ���ʧ��",
                "dodge":		0,
		"parry":		0,
                "damage":		20,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "���ٻ���",
                "action":
"$Nһ���޺����$n���л�����ֹ���ô˻��ᣬ$Nһ������$n��$l��\n"
"ԭ�����廢���ŵ��е�ɱ�֡����ٻ�����",
		"dodge":		0,
		"parry":		0,
                "damage":		25,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "����ƽ��",
                "action":
"$N���ƻ��������ڵ��ϣ�����$w������$n��˫����ȥ",
                "dodge":		0,
		"parry":		0,
                "damage":		10,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ﻢ����",
                "action":
"$Nվ�������������֮��������$w�У���$n��������һ����\n"
"���С��ﻢ���¡�������Ȼ������������Ȼ��Ч",
                "dodge":		0,
		"parry":		0,
                "damage":		30,
                "damage_type":  "����"
        ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
		return notify_fail("�����������������ѧ�廢���ŵ��� ����Щ���������ɡ�\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");

        return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
	if ((int)me->query("force") < 5)
		return notify_fail("��������������޷���ϰ�廢���ŵ���\n");
	me->receive_damage("kee", 20);
	me->add("force", -3);
	message_vision("$N������ѧ����һ���廢���ŵ���\n", me);
	return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
