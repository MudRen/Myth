//�������޵�
// dodge -10	parry -5	damage 25

inherit SKILL;

mapping *action = ({
        ([      "name":		"���������������У��������տ�������",
		"action":	"$Nһʽ���������������У��������տ�����������̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���
�Ե�����������$w������Ϣ�ش���$n��$l",
		"dodge":	-10,
		"parry":	0,
		"damage":	20,
		"damage_tupe":	"����",
		"parry_msg":	"$Nһʽ���������������У��������տ�����������̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���",
		"parry_power":	0,
	]),
	([	"name":		"���ٳ��ӹĳ���ҹ�������Ǻ������졹",
		"action":	"$Nһʽ���ٳ��ӹĳ���ҹ�������Ǻ������졹����ռ������λ��
����$w����һ������, �����ӵ�к�����$n$l",
		"dodge":	-10,
		"parry":	0,
		"damage":	25,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���ٳ��ӹĳ���ҹ�������Ǻ������졹����ռ������λ��
����$w����һ������, �Ŀ�$n�Ĺ���",
		"parry_power":	0,
	]),
	([	"name":		"����������»�Ȫ������ãã�Բ�����",
		"action":       "$Nһʽ����������»�Ȫ������ãã�Բ�������������λ��
����$w��Ϊ���쵶Ӱ��������������������$nȫ�����",
		"dodge":	-10,
		"parry":	-10,
		"damage":	25,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ����������»�Ȫ������ãã�Բ�������������λ��
����$w��Ϊ���쵶Ӱ������������������ס$Nȫ�����",
		"parry_power": 0,
	]),
	([	"name":		"��¥���������������д�Լ�����ӡ�",
		"action":	"$Nһʽ��¥���������������д�Լ�����ӡ�����$n������ת��
��ΪһȦ��Ӱ���ڡ��ޡ�λͻ��һ������̩ɽѹ��֮ʽ����$n$l",
		"dodge":	-15,
		"parry":	0,
		"damage":	30,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ��¥���������������д�Լ�����ӡ�����$n������ת��
��ΪһȦ��Ӱ���㿪$n�Ĺ���",
		"parry_power":	0,
	]),
	([	"name":		"���紵����ƮƮ�٣��������������衹",
		"action":	"$Nһʽ���紵����ƮƮ�٣��������������衹�����弱����ת��
�ڡ��롹λ��һ�����磬����$w৵ؿ���$n��$l",
		"dodge":	-10,
		"parry":	0,
		"damage":	20,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���紵����ƮƮ�٣��������������衹�����弱����ת��
�ڡ��롹λ��һ�����磬��ȥ$n�Ĺ���",
		"parry_power": 	0,
	]),
	([	"name":		"�����ݼ�į�����ɣ��滨һ֦�����꡹",
		"action":	"$Nһʽ�����ݼ�į�����ɣ��滨һ֦�����꡹��ռס���ҡ�λ��
������$w��������ǹ⣬����$nȫ��",
		"dodge":	-20,
		"parry":	-10,
		"damage":	30,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ�����ݼ�į�����ɣ��滨һ֦�����꡹��ռס���ҡ�λ��
������$w��������ǹ⣬����$n��$l����ȥ$n�Ĺ���",
		"power_power":	0,
	]),
	([	"name":		"������Ը���������ڵ�ԸΪ����֦��",
		"action":	"$Nһʽ������Ը���������ڵ�ԸΪ����֦������̤��Ǭ����������λ��
����$w������������$n��$l��ȥ",
		"dodge":	-10,
		"parry":	0,
		"damage":	20,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ������Ը���������ڵ�ԸΪ����֦������̤��Ǭ����������λ��
��$n�Ĺ��������˳�ȥ",
		"parry_power":	0,
	]),
	([	"name":		"���쳤�ؾ���ʱ�����˺������޾��ڡ�",
		"action":	"$Nһʽ���쳤�ؾ���ʱ�����˺������޾��ڡ����ɡ�������Ǭ�����ˣ�
����$w����һ��������$n$l��ȥ",
		"dodge":	-20,
		"parry":	-20,
		"damage":	30,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���쳤�ؾ���ʱ�����˺������޾��ڡ����ɡ�������Ǭ�����ˣ�
����$w����һ�����絴����$n�ķ�â",
		"parry_power":	0,
	]),
});
int valid_learn(object me)
{
        object ob;

        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�������޵�ֻ��Ů�Բ�������\n");

        if( (int)me->query("max_force") < 200 )
                return
notify_fail("�������������û�а취ѧ�������޵�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("���������һ�ѵ�����ѧ�������޵�����\n");

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

        if( (int)me->query("kee") < 40 )
                return
notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

