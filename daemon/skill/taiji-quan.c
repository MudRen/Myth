//̫��ȭ
//�䵱����ȭ������
//by junhyun@SK

inherit SKILL;
#include <ansi.h>

mapping *action = ({
  ([
    "name":             "������ʽ��",
    "action":
"$N��̫��������ʽ����˫���´����ֱ����⣬��������������������ǰ",
    "force":            50,
    "dodge":            -10,
    "parry":            -10,
    "damage_type":      "����",
  ]),
  ([
    "name":             "����ȸβ��",
    "action":
"$N����һ�С���ȸβ����˫�ֻ��˸���Ȧ����������������$n��$l",
    "force":            100,
    "dodge":            10,
    "parry":            -10,
    "damage_type":      "����",
  ]),
  ([
    "name":             "�����ޡ�",
    "action":
"$N���$n��һ�С����ޡ���������ȭ�������ϻ�����һǰһ�����ƽ��",
    "force":            70,
    "dodge":            10,
    "parry":            10,
    "damage_type":      "����",
  ]),
  ([
    "name":             "���������ơ�",
    "action":
"$N���С��������ơ�������������������ǰ����۰뻷���ұ�ֱ�죬����$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "���׺����᡹",
    "action":
"$N���Ŷ����������鰴������ʹһ�С��׺����᡹����ȭ��ץ��$n��$l��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),
  ([
    "name":             "��§ϥ������",
    "action":
"$N����΢�����鲽��һ�ǡ�§ϥ��������������ǰ�����»�������$n$l��",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "���ֻ����á�",
    "action":
"$N�ұ۰뻷������������һ�С��ֻ����á���ʮָ���ţ���������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),  ([
    "name":             "��ָ�ɴ���",
    "action":
"$N�����������������黮���������»�����ȭ��һ�ǡ�ָ�ɴ�������$n���ɲ�",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��˫������",
    "action":
"$N˫���»���ȭ�������ǰ������Ȧ��һ�С�˫�������������������$n��̫��Ѩ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "���������š�",
    "action":
"$N�󲽳��飬���������鰴�����ֳ�����ʹһ�С��������š�����$n��$l��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),  ([

    "name":             "����̽��",
    "action":
"$N�ҽ����������ֻ�Ȧ�󸧣�һ�С���̽��������Բת��ǰ����$n���Ż�ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "������ʽ��",
    "action":
"$Nʩ��������ʽ�����������⻮��ס$n��������������ָ������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "����׿�����",
    "action":
"$N���ֱ��ƺ�����ǰ��������ȭ�����´�����һ�С���׿�����������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "�������롹",
    "action":
"$N���ǰ̤�벽����������ʹһ�С������롹����ָ�������ϴ���$n���ɲ�",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "ץ��",
  ]),  ([

    "name":             "����ͨ�ۡ�",
    "action":
"$Nһ�С���ͨ�ۡ������һ������������$n��ǰ�������Ͼ���Ʋ������̫����������$n",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "�������ơ�",
    "action":
"$N�ҽ�̤������������ȭ�黮�����ƻ��б��£���ǡ������ơ�һ�����㽫$n����̫��Ȧ��",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "��������",
    "action":
"$N�����������ȡ��ɿ衢��������ϥ������������һ�С�������������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "���𼦶�����",
    "action":
"$N���������ҽŶ�����ʹһ�С��𼦶�������˫ȭ����������̫��ȦȦ��$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "����Ů����",
    "action":
"$N������̤��˫����ȭ�����ӳ���ʹһʽ����Ů���󡹣�˳��$n�ֱ�ֱ�ϣ�����$nǰ��",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "������Ʋ����",
    "action":
"$N���ֻ�Ȧ�����־���ǰ��������ǰƲ����ʹһ�С�����Ʋ��������$n��$l��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��ת����ȡ�",
    "action":
"$N�����鰴�����ֱ���������黮һ�С�ת����ȡ��������������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "���Դ���",
    "action":
"$N����һ�С��Դ��������ֻ�̫��Ȧ§��ϥ��������ȭ���»���������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "���������ǡ�",
    "action":
"$N��̤���Ƿ�λ�������ң�˫ȭ�����ʮ�֣�һ�С��������ǡ�����$n��$l��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "������",
    "action":
"$N����΢ת��������ֱ���ұ�΢����������ϣ�ʹһ�С�����������$n���ֱ˦��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "��ת�������",
    "action":
"$N˫���쿪������������һ����Բ����һ�С�ת�����������$n������������������̫��Ȧ��",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "���乭�仢��",
    "action":
"$N���ֻ������գ�������ȭ��ǰ�Ƴ���ȭ�������һ�С��乭�仢����ֱ��$n$l��ȥ",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "�����֡�",
    "action":
"$Nʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$n$l��ס��̫���ᾢ�漴����",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "�����Ծ��",
    "action":
"$N����һ�������Ծ����˫�ֻ�̫��Ȧ����$n�Ĺ�������������ץ��$n������������",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��б���ơ�",
    "action":
"����$Nһ�С�б���ơ�����$n������ƫ��˫ȭ�ڻ������������ɾ���һ������$n",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��������ɽ��",
    "action":
"����$N���С�������ɽ����˫ȭ����������бת����$n���һ�ƣ���������Ҫ��$n�Ƴ�",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��Ұ����ס�",
    "action":
"$N������Ұ����ס���ת��$n�����ǰ�������ƽ����$n����һ�����뽫�����",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "������Ʊա�",
    "action":
"$N�����ֱ��������ƣ����ֽ��棬�̶����ҷֿ����ɰ��С�����Ʊա�����$n$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��ʮ���֡�",
    "action":
"$N����΢��ת����ϥ���裬���С�ʮ���֡�����ֻ�ֱ�΢�������ֱ��������໮������",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([

    "name":             "��������������",
    "action":
"$N������ֱ�������黮�������ұ��������һ�ǡ�����������������$n��$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),  ([
    "name":             "�����ơ�",
    "action":
"$N��ǰ������ǰ�죬���ҷֿ�����΢���������ƽ��������������������$n$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "����",
  ]),


});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��̫��ȭ������֡�\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
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
return CLASS_D("quest") + "/taiji-quan/" + func;
}

