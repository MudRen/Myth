// ħ�ʵ���
//��ԯ��Ĺ���⹥������
//by junhyun@sk
//

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$Nһ��"+HIW"����Ӱ����"NOR"����$w��Ӱ���ε�������$n����Ҫ��֮����",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIM"������Ʊա�"NOR"������$w����ֲ�͸�磬��$nΧ�ڵ���֮�У�",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIG"��������ա�"NOR"����$w����һ����������Ӱ�ɳ�����$n��$l��",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIC"��ն�����"NOR"���е�$w������ͣ�б�̴̵�ɨ��$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIR"�����Ƴ��ա�"NOR"����$w����˿˿����������»���$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIM"��ѪȾ������"NOR"˫�ֽ���$w���ű��˵�ɱ��������$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 80 )
                return
notify_fail("�������������û�а취ѧħ�ʵ�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("���������һ�ѵ�����ѧħ�ʵ�����\n");

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
                return notify_fail("���������һ�ѵ���������������\n");

        if( (int)me->query("kee") < 40 
   ||   (int)me->query("force") < 5 )
                return
notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/mohuang-blade/" + func;
}

