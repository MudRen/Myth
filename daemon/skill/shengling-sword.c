// ʥ�齣��
//��ԯ��Ĺ���⹥������
//by junhyun@sk
//

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$Nһ��"+HIW"�����¡�"NOR"����$w������ʣ�����һ�����£�",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIM"��˫�¡�"NOR"����$w��â���£���$nΧ�����У�",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIG"�����¡�"NOR"����$w����һ����������Ӱ����$n��",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIC"�����¡�"NOR"���е�$w�ƿ�֮���������Ĵ���$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIR"�����¡�"NOR"����$w���������벻���ĽǶȻ���$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIM"�����¡�"NOR"˫�ֽ���$w���ű��˵�ɱ��������$n��$l",
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
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("���������һ�ѽ�����ѧʥ�齣����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ���������������\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("����������������Ž�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/shengling-sword/" + func;
}

