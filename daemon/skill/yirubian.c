 //Cracked by Roath
//������ޡ�dhxy-evil 2000.7.5
//�޷��������������ˣ��Ը����,����������ࡣ
//ϰ����Ů,�̽��������޷���ʽҲ�Ǽ�����������һ���Ұ��Һ�.
//����鰮����ͷ��������Թ�£�ϰ������Ҳ��ѧ����say koker
inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : "$N����$w��һʽ"HIM"����Х������"NOR"�����Ӱ�д�����������������������",
"dodge"  : -5,
"damage" : 20,
"parry"  :  5,
"name"   : "��Х����",
"damage_type" : "����",
]),
([
"action" : 
"$N�㷢�����̬��ǧ��ʹ��һ��"HIM"��������ǣ��"NOR"�������д�������Ʈ�ݣ�����ˣ�",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"lvl"         : 10,
"damage_type" : "����",
"name"   : "������ǣ",
]),
([
"action" : 
"$N����ʹ��"HIM"��������ʿ��"NOR"���ɾ�˳�ƴ���$n���ƣ��������\n"
"�������ݸ��ˣ���ɽ������֮�У�������ǽ��ơ�",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"lvl"         : 20,
"damage_type" : "����",
"name"   : "������ʿ",
]),
([
"action" : 
"$N�ؽ�ָ���Լ��Ŀڣ�˲��������ȥ�������һ�ɺ�⣬������ӿȪ���ˣ�\n"
"����һƬѪ��������"HIM"����Ѫ���ġ�"NOR"��ӳ������ü���Գ࣬�ۼպ��Σ����ݶ��ˡ�",
"dodge"  : -10,
"damage" : 30,
"parry"  : -10,
"lvl"         : 30,
"damage_type" : "����",
"name"   : "��Ѫ����",
]),
([
"action" : 
"$N�������ֳ�����ޣ����泯$n��ȥ��$n��æ�ӿ���$N���һ����"
"һ��"HIM"����Ե���䡹"NOR"������š�",
"dodge"  : 0,
"damage" : 20,
"parry"  : 0,
"lvl"         : 40,
"damage_type" : "����",
"name"   : "��Ե����",
]),
([
"action" : 
"$N����΢�࣬һ��"HIM"���ٷ������"NOR"������ʮ�ɱ�â�����ռ�����$n��"
,
"dodge"  : -10,
"damage" : 25,
"parry"  : -10,
"lvl"         : 50,
"damage_type" : "����",
"name"   : "�ٷ����",
]),
([
"action" : 
"ֻ��$Nһ·"HIM"�����޺ۡ�"NOR"��$w��Ȼ�Ӷ���$n������Щ�������⣮",
"dodge"  : -10,
"damage" : 20,
"parry"  : -10,
"lvl"         : 60,
"damage_type" : "����",
"name"   : "���޺�",
]),
([
"action" : 
"$Nһʽ"HIM"���������̡�"NOR"������$w���²������·�����˵�����ԹŶౡ��������һ����ʱ�ѡ�",
"dodge"  : -20,
"damage" : 30,
"parry"  : 0,
"lvl"         : 70,
"damage_type" : "����",
"name"   : "��������",
]),
([
"action" : 
"$Nһ����߳��$w��ز���裬һ·"HIM"������š�"NOR"��������ƴ�������ɢ��ƬƬ�ɻ���ˮ����",
"dodge"  : 0,
"damage" : 30,
"parry"  : 10,
"lvl"         : 80,
"damage_type" : "����",
"name"   : "�����",
]),
([
"action" : 
"$Nüͷһ�壬��Ȼ���У���$w���ɣ�"HIM"�����ǵ�㡹"NOR"��$n����ǰ��ȥ��",
"dodge"  : -10,
"damage" : 20,
"parry"  : 0,
"lvl"         : 90,
"damage_type" : "����",
"name"   : "���ǵ��",
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취������ޡ�\n");
        if(me->query("family/master_id") != "lin yueru" && 
            me->quert("family/master_name" != "��ɽ����") )
		return notify_fail("�����ʹ��˼��ޣ�ȴ��֪�����ϰ��\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ���������ޡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}	
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}	
int practice_skill(object me)
{
        if( (int)me->query("kee") < 100
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ����ޡ�\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
//        write(HIR"�������̣�������ǣ������������˼�\n"NOR,me);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/yirubian/" + func;
}
