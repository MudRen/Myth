//longma-spear ����ǹ�� by angell

/*
����ǹ������ʽ������
�ϲ�Ϊ��������ʽ������Ʈ�ݣ������м�
�²�Ϊ����������ʽ�����ư��磬�����޴�
��������ǹ���Ͳ������׹�ͨ��ʱ��
������һʽ�����޴�Ŀ˵����г���
*/

inherit SKILL;
mapping *action = ({
        ([      "action":
"$N����$w��ǰһͦ����ǹ��һ��һʽ��һ���ȡ���$nֱ�������",
                "damage":               20,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���²�ͣ��һ��ɱ�������$wͻȻ���һ�ݣ���һʽ��������׷�����ǿ쵽�˼��㣡",
                "damage":               15,
                "dodge":                -15,
                "parry":                -5,
                "damage_type":  "����"
        ]),
         ([      "action":
"$Nһ�����������ǹ������ָ$n˫��˫�ź��������ף���һ�п��и����ã��С������ʬ����",
                "damage":               30,
                "dodge":                0,
                "parry":                -5,
                "damage_type":  "����"
        ]),
         ([      "action":
"$N������$w������÷�һ��������˷�����ǹ��������Ӱ����һ�С������ڡ���",
                "damage":               15,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
         ([      "action":
"ֻ��$N����$w���ر����ĥ�������������ѣ���һʽ������ǳˮ��ίʵ�����мܣ�",
                "damage":               30,
                "dodge":                10,
                "parry":                -15,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����������$w���ű��˵����ƾ���$n�����С����ڽ�����һ�֣������޹⣬����ɫ�䣬��ʵ���˹�Ŀ�࿴��",
                "damage":               35,
                "dodge":                20,
                "parry":                -20,
                "damage_type":  "����"
        ]),
 ([      "action":
"$N���ζ��䣬�������У�$w���Ҵ��������ƺ����·������⡸��ս��Ұ��������м����ܹ���͸ѽ��",
                "damage":               40,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "����"
        ]),
 ([      "action":
"$N��Ȼ�������$wֱ��ֱ��ֱָ$n�����С�������ʡ�ʵ�ڲ���С�ӡ�",
                "damage":               35,
                "dodge":                20,
                "parry":                -20,
                "damage_type":  "����"
        ]),
 ([      "action":
"$N����$w����$nԽתԽ�죬ǹ�����У���������$n��ʱΪ���С���������������",
                "damage":               40,
                "dodge":                -20,
                "parry":                -20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취������ǹ����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");
if( (int)me->query_skill("longma-spear",1) < (int)me->query_skills("longma-steps",1) )
                return
notify_fail("����������������죬�޷�ѧϰ���ߵ�����ǹ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon, int total)
{
    total=3;
    if (me->query_skill("longma-spear", 1) > 99)
        total=7;
  if (me->query_skill("longma-spear", 1) > 199 && me->query_skill("longma-steps",1) > 199)
        total=8;
    return action[random(total+1)];
}


int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");
if( (int)me->query_skill("longma-spear",1) < (int)me->query_skills("longma-steps",1) )
                return
notify_fail("����������������죬�޷�������ߵ�����ǹ����\n");
        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ������ǹ����\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/longma-spear/" + func;
}
