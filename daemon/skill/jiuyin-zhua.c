//�����׹�צ
//��ԯ��Ĺ����ȭ��
//by ivy 2002.2.9

//  ɭȻ���׹� ���µ����� �����Ѻ��� �������ķ� 
//  ��˼����� ��ָ�Ʋ��� �����ѻ��� צ�ֹ�����

inherit SKILL;
#include <ansi.h>

mapping *action = ({
  ([
    "name":             "��ɭȻ���׹ǡ�",
    "action":
"$Nʹһ�С�"+BLINK""+HIW"ɭȻ���׹�"NOR"������ָ�繳������$n��$l",
    "force":            50,
    "dodge":            -10,
    "parry":            -10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "�������Ѻ��ѡ�",
    "action":
"$N������磬ʮָ΢΢������һ�С�"+BLINK""+HIR"�����Ѻ���"NOR"��ץ��$n��$l",
    "force":            100,
    "dodge":            10,
    "parry":            -10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "�����µ����ա�",
    "action":
"$N����һ�������ּ�����һ�С�"+BLINK""+HIC"���µ�����"NOR"�����͵�ץ��$n��ͷ��",
    "force":            70,
    "dodge":            10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "���������ķ���",
    "action":
"$Nʹһ�С�"+BLINK""+HIB"�������ķ�"NOR"������������ľ��磬ײ��$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "����˼����ǡ�",
    "action":
"$Nһ�С�"+BLINK""+HIW"��˼�����"NOR"����ʮָ��ꪣ�����$n�Ķ���",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "����ָ�Ʋ�����",
    "action":
"$N˫�ֺ������֣�һ�С�"+BLINK""+HIR"��ָ�Ʋ���"NOR"�������Ȱ�ץ��$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),  ([
    "name":             "�������ѻ��֡�",
    "action":
"$Nʹһ�С�"+BLINK""+HIW"�����ѻ���"NOR"����ʮָ���������Ϯ��$nȫ�������Ѩ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),  ([
    "name":             "��צ�ֹ�������",
    "action":
"$N����ָ�죬����ָ�أ������������磬һ�С�"+BLINK""+HIC"צ�ֹ�����"NOR"������$n�Ķ���",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),


});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������׹�צ������֡�\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query("class") != "yaomo")
                return notify_fail("�ٺ٣�һ��������ζ���ħ����\n");
        if( (int)me->query("sen") < 40)
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("kee", 30);
        me->add("force", -10);

        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/jiuyin-zhua/" + func;
}

