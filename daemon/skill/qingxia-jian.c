// ��ϼ����
// coded by lestat 2/2/2001
// updated by xintai 2/3/2001

// ��ϼ���� dodge -10   parry -10  damage 20 force 100


inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : 
"$Nʹ��"+BLINK""+MAG"������С�á�"NOR"�������𣬽�����ָ�����������ƣ�ֱ��$n��$l",
"dodge"  : -20,
"damage" : 15,
"parry"  : 10,
"force"         : 50,
"skill_name"  : "������С�á�",
"damage_type" : "����",
]),
([
"action" : 
"$N����$w��������һ�̣�������������ʹ��"+BLINK""+MAG"��ɨѩ��衹"NOR"��",
"dodge"  : -20,
"damage" : 10,
"parry"  : -10,
"force"         : 60,
"skill_name"  : "��ɨѩ��衹",
"damage_type" : "����",
]),
([
"action" : 
"$N���ƺ����ǰ��������$w����ӷ���ȴ��һ��"+BLINK""+MAG"�����ٰ�����"NOR"",
"dodge"  : -10,
"damage" : 15,
"parry"  : -5,
"force"         : 40,
"skill_name"  : "�����ٰ�����",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"�����¶��ġ�"NOR"��$w���������һ���󻡣�����$n��$l",
"dodge"  : 0,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "�����¶��ġ�",
"damage_type" : "����",
]),
([
"action" : 
"$N����������ң�������Ϊ������$n��ȴ��һ��"+BLINK""+MAG"���رߵ��ס�"NOR"",
"dodge"  : -15,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "���رߵ��ס�",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"��С԰�վա�"NOR"������$wѸ����$n��������������",
"dodge"  : -15,
"damage" : 20,
"parry"  : -5,
"force"         : 50,
"skill_name"  : "��С԰�վա�",
"damage_type" : "����",
]),
([
"action" : "$Nʹ��"+BLINK""+MAG"������ҹ����"NOR"������$w�й�ֱ�룬����$n��$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "������ҹ����",
"damage_type" : "����",
]),
([
"action" : 
"$N��������ҵͣ�һ��"+BLINK""+MAG"���������䡹"NOR"��$w�ڿ��л���һ���⻷������$n",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 70,
"skill_name"  : "���������䡹",
"damage_type" : "����",
]),
([
"action" : "$N����$w���¶��Ͼ��������������һ�㣬ȴ��"+BLINK""+MAG"�������ٳء�"NOR"",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 80,
"skill_name"  : "�������ٳء�"NOR"",
"damage_type" : "����",
]),
([
"action" : 
"$N���ֽ���һ�죬����$wƽƽ����$n��$l����һ��"+BLINK""+MAG"��˫���Իء�"NOR"",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 100,
"skill_name"  : "��˫���Իء�",
"damage_type" : "����",
]),
([
"action" : 
"$N����$w�����̣�һ��"+BLINK""+MAG"�����Ƴ��ԡ�"NOR"��ֱָ$n��$l",
"dodge"  : -10,
"damage" : 35,
"parry"  : -25,
"force"         : 120,
"skill_name"  : "�����Ƴ��ԡ�",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"�������չȡ�"NOR"��$w���������һ�ӣ���$n����˼��ĽǶȹ���",
"dodge"  : -10,
"damage" : 20,
"parry"  : -25,
"force"         : 120,
"skill_name"  : "�������չȡ�",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹ��"+BLINK""+MAG"���軨��·��"NOR"��һʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 110,
"skill_name"  : "���軨��·��",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"��İ·��ɣ��"NOR"��$w�������㣬����$n��$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : -15,
"force"         : 120,
"skill_name"  : "��İ·��ɣ��",
"damage_type" : "����",
]),
([
"action" : 
"$N���Ų�������$wͻȻ���Լ������´̳���ȴ��һ��"+BLINK""+MAG"�����Ľ�����"NOR"",
"dodge"  : -10,
"damage" : 50,
"parry"  : -25,
"force"         : 130,
"skill_name"  : "�����Ľ�����",
"damage_type" : "����",
]),
([
"action" : 
"$N������ˮ�滬��һ�㣬һ��"+BLINK""+MAG"��������ҹ��"NOR"��ƽƽ����$n��$l��ȥ",
"dodge"  : 0,
"damage" : 20,
"parry"  : -25,
"force"         : 80,
"skill_name"  : "��������ҹ��",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"���������"NOR"������$w�̵�$n������",
"dodge"  : -10,
"damage" : 15,
"parry"  : -5,
"force"         : 100,
"skill_name"  : "���������",
"damage_type" : "����",
]),
([
"action" : 
"$Nһ��"+BLINK""+MAG"��ĵ�����᡹"NOR"��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ",
"dodge"  : -15,
"damage" : 20,
"parry"  : 15,
"force"         : 150,
"skill_name"  : "��ĵ�����᡹",
"damage_type" : "����",
]),
([
"action" : 
"$N��������棬������ǰһ�ˣ�һ��"+BLINK""+MAG"����ҩ���项"NOR"��$w��$n��$l��ȥ",
"dodge"  : 0,
"damage" : 15,
"parry"  : -15,
"force"         : 150,
"skill_name"  : "����ҩ���项",
"damage_type" : "����",
]),
([
"action" : 
"$N������Ȼ֮ɫ������һ��"+BLINK""+MAG"������Բԡ�"NOR"��$w����$n��$l",
"dodge"  : -25,
"damage" : 25,
"parry"  : -25,
"force"         : 180,
"skill_name"  : "������Բԡ�",
"damage_type" : "����",
]),
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
    if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("��ϼ�������������˿���ľ����ķ���������\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "sword")
	return notify_fail("�������������û������ô����ϼ�������� :)\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("kee", 30);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 80 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 80) / 4 );
                switch(random(3)) {
                        case 0: return HIW"$n���ϱ���������һ����ɼ��ǵ��˿ڣ�\n"NOR;
                        case 1: return HIW"$N����һ�£�һ��������$w�г������$n��$l��\n"NOR;
                        case 2: return HIW"$N�ͺ�һ����$w�Ͻ�â������˸��\n"NOR;
                }
        }

}


string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/qingxia-jian/" + action;
}
