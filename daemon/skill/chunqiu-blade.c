//���ﵶ
inherit SKILL;
mapping *action = ({
        ([      "name":         "���������¡�",
                "action":       "$Nһʽ���������¡����������棬
����һ�Σ���$n��ǰ��ȥ��������$n���Գ��֣�
�ӵ����裬����$w������Ϣ�ش���$n��$l",
                "dodge":        5,
                "parry":        0,
                "damage":       20,
                "damage_tupe":  "����",
                "parry_msg":    "$Nһʽ���������¡����������棬
����һ�Σ���$n��ǰ��ȥ��������$n���Գ���",
                "parry_power":  0,
        ]),
        ([      "name":         "��������ʵ��",
                "action":       "$Nһʽ��������ʵ������ס�Ų���
����$w����һ����â, ����ʵ�죬����$n$l",
                "dodge":        10,
                "parry":        -10,
                "damage":       25,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ��������ʵ������ס�Ų���
����$w����һ����â, ��$n��ȥ",
                "parry_power":  0,
        ]),
        ([      "name":         "��������ա�",
                "action":       "$Nһʽ��������ա���չ�����Σ�
����$w�ó�������������$nȫ����ȥ",
                "dodge":        10,
                "parry":        -5,
                "damage":       25,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ��������ա���չ�����Σ�
����$w�ó�������������ס$Nȫ��Ҫ��",
                "parry_power": 0,
        ]),
        ([      "name":         "�����ݱ����š�",
                "action":       "$Nһʽ�����ݱ����š����ӿ첽����
���λ���һ�Ż�Ӱ�������벻��֮����������$n$l����һ��",
                "dodge":        15,
                "parry":        -10,
                "damage":       30,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ�����ݱ����š����ӿ첽����
���λ���һ�Ż�Ӱ���㿪$n�Ĺ���",
                "parry_power":  0,
        ]),
        ([      "name":         "���ﻨ����١�",
                "action":       "$Nһʽ���ﻨ����١������弱����ת��
һ������������$w৵ش�в�¿���$n��$l",
                "dodge":        10,
                "parry":        0,
                "damage":       20,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ���ﻨ����١������弱����ת��
һ����������ȥ$n�ķ��������Ĺ���",
                "parry_power":  0,
        ]),
        ([      "name":         "�����紵������",
                "action":       "�ۼ�$N�����Ѿ���������һʽ�����紵��������
����$w��һ����˼��֮�Ƕȣ�����$nҪ��",
                "dodge":        20,
                "parry":        -5,
                "damage":       30,
                "damage_type":  "����",
                "parry_msg":    "�ۼ�$N�����Ѿ���������һʽ�����紵��������
����$w��һ����˼��֮�Ƕȣ�����$n��$l",
                "power_power":  0,
        ]),
        ([      "name":         "�������޺ۣ�����޷���",
                "action":       "$Nһʽ�������޺ۣ�����޷������Ų��鲽��
����$w�����ھ����Ӽ���������$n��$l��ȥ",
                "dodge":        5,
                "parry":        0,
                "damage":       20,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ����ɽ�ּ��ء����Ų��鲽��
����$w�����ھ����Ӽ���������$n��$l��ȥ�����$n���Ϸ���",
                "parry_power":  0,
        ]),
        ([      "name":         "����ɽ�ּ��ء�",
                "action":       "$Nһʽ����ɽ�ּ��ء�������ƵƵ��λ��
����$w��ѹ��֮���������ص���,����$n����ҪѨ",
                "dodge":        20,
                "parry":        -20,
                "damage":       30,
                "damage_type":  "����",
                "parry_msg":    "$Nһʽ����ɽ�ּ��ء�������ƵƵ��λ��
����$w��ѹ��֮���������ص���,�漴�ѳ�$n�Ĺ���",
                "parry_power":  0,
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return
notify_fail("�������������û�а취ѧ���ﵶ����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("û�е�����ôѧ���ﵶ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("û�е�����ô�����ﵶ����\n");

        if( (int)me->query("force") < 50 ) return notify_fail("����������㣬û�취�赶Ūǹ��\n");
        if( (int)me->query("kee") < 50 )
                return
notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("zhenwu") + "/chunqiu-blade/" + action;
}

