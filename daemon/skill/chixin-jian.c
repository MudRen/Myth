// jueqing-bian.c
// �����鳤����
// Juney: 07/04/97: Genesis.
/*�����鳤��Ϊ�׾����������޷�������˿�����������ֱ������������
*/
inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"����Ͷ���չ���ա�"NOR+"����¶΢Ц������$wһ��������
����������$n��$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "����Ͷ���չ���ա�",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"��ͻ�������������"NOR+"���������������ж��䣬����$w
��һ�����벻���ķ�λбб����$n��$l",
"dodge"  : -10,
"damage" : 15,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "��ͻ�������������",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"������ĺĺƵ˼�䡻"NOR+"���������ߣ����׸���Ƭ�̣���
������$w��Ȼ���ϣ�����$n��$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : -20,
"force"         : 100,
"skill_name"  : "������ĺĺƵ˼�䡻",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"��ǧ��濾�ֻ�ǿա�"NOR+"������һ�Σ����Ӷ��ϣ�����$w
����һ������׼$n��$l��������",
"dodge"  : 10,
"damage" : 25,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "��ǧ��濾�ֻ�ǿա�",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"��������������须"NOR+"��һ����������$n����Ӱ���棬
����$w���Ȼ��������$n��$l��ȥ",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "��������������须",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"��ȴ���칫��������"NOR+"��һ����������$w����б����
��ֱָ$n��$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"force"         : 100,
"skill_name"  : "��ȴ���칫��������",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"�������޶���˼�ࡻ"NOR+"��΢΢һ��ת������$wȴ����
���´���������$n��$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"force"         : 100,
"skill_name"  : "�������޶���˼�ࡻ",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"���˺������޾��ڡ�"NOR+"����ɫ΢�䣬���ж�Ȼ���������
�ȣ�����$w��ƥ��������$n��$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "���˺������޾��ڡ�",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"����Ȼ���������桻"NOR+"���������ף�����̾�˿���������
Ө����������������$w�й�ֱ����Ѹ���ޱȵ���$n��$l��ȥ",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "����Ȼ���������桻",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"��Ը�˳��ÿ��źޡ�"NOR+"�������Ծ������$w�ڰ�������£�
����һ����ɫ��������$n��$l",
"dodge"  : 20,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "��Ը�˳��ÿ��źޡ�",
"damage_type" : "����",
]),
([
"action" : "$Nʹһʽ"+BLINK""+HIC"������δ���ɰ�ͷ��"NOR+"������ಽ������$w���ּ���������
��ৡ���һ����$n��$l��ȥ",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "������δ���ɰ�ͷ��",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"������������ǰԵ��"NOR+"����ؼ���һ�����ֳ�ǰ����������
$w��Ϊ�⻡��$n��$l��ȥ",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "������������ǰԵ��",
"damage_type" : "����",
]),
([
"action" : "$Nʹһʽ"+BLINK""+HIC"�����鲻�Ƽ��Ƹ֡�"NOR+"������Ծ�𣬲�����Ӱ������ȴ�ִ�
����д��£�˫������$w�����Ʊ��˵ش���$n��$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "�����鲻�Ƽ��Ƹ֡�",
"damage_type" : "����",
]),
([
"action" : 
"$Nʹһʽ"+BLINK""+HIC"�������칫�����ۡ�"NOR+"������$w���͡���һ��б������գ�
�漴���¡��ৡ����£�����һ�����֣���$n��$l��ȥ",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "�������칫�����ۡ�",
"damage_type" : "����",
]),
([
"action" : "$Nʹһʽ"+BLINK""+HIC"���ճ��˻�����ʱ��"NOR+"������΢̧������$w���·�����
����һ�ɾ��練��$n��$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "���ճ��˻�����ʱ��",
"damage_type" : "����",
]),
([
"action" : 
"$N�㾡ȫ�����"+BLINK""+HIC"����������鳤����"NOR+"����ɫʮ�ּ�������������
����������$w���費ͣ��ȫ�������������˵Ľ����У�$n���ɺ�Ȼ��ֻ��$N
����΢�䣬�����������ѱ���$n��$l",
"dodge"  : -10,
"damage" : 50,
"parry"  : -25,
"force"         : 200,
"skill_name"  : "����������鳤����",
"damage_type" : "����",
]),
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
	return notify_fail("��ľ����ķ�Ϊ��ǳ��û��ѧ�����鳤����\n");
    if ((int)me->query_skill("yueying-wubu", 1) < 20)
        return notify_fail("�����Ӱ�貽��Ϊ��ǳ��û��ѧ�����鳤����\n");
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
	return notify_fail("�������������û������ô�������鳤������ :)\n");
	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("�����鳤�������������˿���ľ����ķ���������\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
    me->receive_damage("kee", 30);
//        write(HIM"���ճ��˻�����ʱ,��������鳤����\n"NOR);
    return 1;
}
void skill_improved(object me)
{
        if( (int)me->query_skill("chixin-jian", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 50);
        }
}

string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/chixin-jian/" + action;
}
