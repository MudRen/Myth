//���ױ޷�
//��ԯ��Ĺ����޷�
// by ivy 2002.2.9
// ���׹����ƺ��� ���ױ���ľҡ ������������� ��������������
#include <ansi.h>
inherit SKILL;
mapping *action =
({
([
"action" : "ֻ��$N����ᶶ��һʽ"+HIG"�����׹����ƺ�����"NOR"��$w�����ϻ����������ˣ�ԴԴ����!",
"dodge"  : -5,
"damage" : 40,
"parry"  : -10,
"lvl"         : 0,
"skill_name"  : "���׹����ƺ���",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+HIC"�����ױ���ľҡ��"NOR"���Ӷ�$w�������߶�ʮһ§ͷ���£�$n��ʱ�������ܱ�һ�����εľ�������Χ��",
"dodge"  : -10,
"damage" : 50,
"parry"  : 5,
"lvl"         : 10,
"skill_name"  : "���ױ���ľҡ",
"damage_type" : "����",
]),
([
"action" : 
"$Nһʽ"+HIY"�� ������������졹"NOR"��$w��$N�����Ƶ���ȼ�����㣬$n����һ�ݣ�����һ�������Ѿ�����$l",
"dodge"  : -5,
"damage" : 60,
"parry"  : 5,
"lvl"         : 20,
"skill_name"  : "�������������",
"damage_type" : "����",
]),
([
"action" : 
"$N����ͻȻһ����������$w��Ӱ���Σ�����Ȱ㣬��Ȼ��һ��"+HIW"���������������ġ�"NOR"ֱ��$n������",
"dodge"  : -10,
"damage" : 30,
"parry"  : -10,
"lvl"         : 30,
"skill_name"  : "��������������",
"damage_type" : "����",
]),

});

int valid_enable(string usage) {
    return usage == "mace" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("jiuyin-force",1) < 40 )
        return notify_fail("�����������澭��Ϊ��ǳ��û��ѧ���ױޣ�\n");
    if ((int)me->query_skill("kongming-steps", 1) < 50)
        return notify_fail("��Ŀ�ڤ������Ϊ��ǳ��û��ѧ���ױޣ�\n");
    return 1;
}

mapping query_action(object me, object weapon) 
{

        return action[random(sizeof(action))];

}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)(weapon->query("skill_type")) != "mace")
        return notify_fail("�������������û���ӣ���ô�����ױް��� :)\n");
    if ((int)(me->query("kee")) < 50)
        return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("kee", 30);
    return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("gumu") + "/yinlei-mace/" + action;
}

