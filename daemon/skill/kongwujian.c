//���޽�
//by dewbaby 12.2002

//�������� �չ����� ��������
//������ �������� �������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ڿ�Ծ�𣬻���һ��"BLINK" "WHT"���������롹"NOR"������$w��������$n��$l",
        "force"  : -30,
        "damage" : 30,
        "damage_type" : "����"
]),
 ([      "action" : "$N��������أ���ͷ��Ц��һ��"BLINK" "HIB"���չ����项"NOR"����������$n��$w��$n������ס���������ã�",
        "force"  : -30,
        "parry"  :  5,
        "damage" : 25,
        "damage_type" : "����"
]),
 ([      "action" : "$Nһ��"BLINK" "HIY"���������С�"NOR"���������ٳ���ʵ���������ء�$w���������������󻡣���$n������ȥ",
        "force"  : -30,
        "parry"  : 5,
        "dodge"  : 5,
        "damage" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N������磬����$wʹ��"BLINK" "HIR"�������ڡ�"NOR"����$n�Ƶ��������ˡ�",
        "force"  : -30,
        "parry"  : 10,      
        "damage" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N���е�$w���̹�������$nһ���ӿ����ס�ˣ�ȴ��һ��"BLINK" "HIG"������������"NOR"����$l",
        "force"  : -30,
        "parry"  :  10,
        "dodge"  : -10,
        "damage" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N��$w�߾���ǰ��һ������$w��Ϊһ���һ����$n��������һ��"BLINK" "HIR"��������䡹"NOR"!",
        "force"  : -30,
        "parry"  :  10,
        "dodge"  : -10,
        "damage" :  40,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("fenxin-spells", 1) < 60)
                return notify_fail("��ķ�������û���ҡ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))]; 
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("��������޷������޽���\n");
        if ((int)me->query("str") <= 20)
        write(WHT"����Ҫ��ǿ����ѽ�������Ǹ����ı�Ǯ��\n"NOR,me);
        me->receive_damage("kee", 20);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("linghai") + "/kongwujian/" + action;
}





