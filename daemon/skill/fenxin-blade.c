//���ĵ���
//fenxin-blade.c
//by dewbaby@sksj 12.2002

//force max=30, dodge max=20, parry max=5

 
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":  "$N����Ծ��һ��"BLINK" "HIC"�����ĺ��ڡ�"NOR"������$w�ڿ��л���һԲ��ֱ����$n������",
        "force":    -30,
        "dodge":    -10,
        "damage":    30,
        "skill_name" : "���ĺ���",
        "damage_type":  "����"
]),
([      "action":  "$Nһ��"BLINK""HIY"�������ƽ���"NOR"��΢΢һЦ�䣬����$wֱ����$n��$l",
        "force":   -30,
        "dodge":   -10,
        "damage":   30,
        "skill_name" : "�����ƽ�",
        "damage_type":  "����"
]),
([  "action":  "$Nһ��"BLINK" "HIB"��������ӡ��"NOR"������$w��Ϊһ�����¹⣬��$n����Χס��$nֻ������һ���ʹ!",
        "force":   -30,
        "dodge":   -20,
        "parry":    -5,
        "damage":   30,
        "skill_name" : "������ӡ",
        "damage_type":  "����"
]),
([  "action":  "$N��ͷ���죬����һ�̣�����$w��ʱ����$n����һ��"BLINK" "HIM"����������"NOR"��ʹ$n��ãʧȥ�˷���!",
        "force":    -30,
        "dodge":    -15,
        "damage":    30,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([  "action":  "$NԾ�ڰ�գ���ͷ��ȻһЦ��һ��"BLINK" "HIW"�����Ļݳ���"NOR"����ˮ��ӿ��$n��$w��$n�ֱ��Ͽ���һ���ʺ�Ŀ���!",
        "force":    -30,
        "dodge":    -15,
        "damage":    30,
        "skill_name" : "���Ļݳ�",
        "damage_type":  "����"
]),
([  "action":  "$N���κ�������������Ʈҡ����������һ��"BLINK" "MAG"�������纣��"NOR"ֱ��$w������ǰ���ŷ���Ϊʱ�������Ƶ��������ˡ�",
        "force":    -30,
        "dodge":    -15,
        "damage":    30,
        "skill_name" : "�����纣",
        "damage_type":  "����"
]),
([ "action":
     "$N�ҽ�������,���ֽ�$w��������, ��һ��"BLINK" "HIR"���Ļ����䡹"NOR"ֱ��$n�ĺ󱳣�$n���϶�ʱ��Ѫ���ܣ�",
        "force":    -30,
        "dodge":    -10,
        "damage":    30,
        "skill_name": "�Ļ�����",
        "damage_type":"����"
]),
 (["action":    "$N������ǰԾ��$n���,���־���һ��"BLINK" "WHT"�����������"NOR"ֻ��һ���������˺۴�$n�ֱ�������,��ֱ�Ҳ��̶�!",
        "force":   -30,
        "dodge":   -15,
        "damage":   30,
        "skill_name": "�������",      
        "damage_type": "����"
]),
(["action":   "$Ņ�����֣��������һЦ��һ��"BLINK" "HIM"���������ġ�"NOR"��$n���ֱۿ�����Ѫ����!",
        "force":  -30,
        "dodge":  -10,
        "damage":  35,
        "skill_name": "��������",
        "damage_type": "����"
]),
(["action":  "$N΢ȻһЦ��˫����һԾ��������$w��Ȼ���Ⱦ�����һ��һ����$nӿȥ��������һ��"BLINK" "HIG"���Ķ�һЦ��"NOR"!",
        "force":  -30,
        "dodge":  -15,
        "damage":  40,
        "skill_name": "�Ķ�һЦ",
        "damage_type": "����"
]),
(["action":   "$N˫���������$w����Ҹ�£������ƺ���Ȼ��վ��ת˲��ȴʹ��һ��"BLINK" "HIW"�������㲡�"NOR",$n��ʱ�ۻ����ң���������������",
        "force":  -30,
        "dodge":  -10,
        "damage":  40,
        "skill_name": "������",
        "damage_type": "����"
]),
(["action":  "$N��������$n��˫Ŀ���飬�������$n���ɻ󲻽⣬$Nȴȫ��ʹ�����һ��"BLINK" "HIR"��ħ��������"NOR"��",
        "force":  -30,
        "dodge":  -10,
        "damage":  35,
        "skill_name": "ħ������",
        "damage_type": "����"
])
});

int valid_enable(string usage) { return (usage == "blade");}

int valid_learn(object me)
{
        object weapon;

        if ((int)me->query("force", 1) < 10)
                return notify_fail("�������������\n");
        if ((int)me->query("sen",1) < 10)
                return notify_fail("��ľ���̫����! \n");
        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������ϰ������\n");
        if( (int)me->query_skill("huanyue-jianfa") <= (int)me->query_skill("fenxin-blade") )
                return notify_fail("��Ļ��½������������޷��ɽ������򵶷���\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
         return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
         return action[random(sizeof(action))]["parry_msg"];
}

string query_dodge_msg(string limb)
{
         return action[random(sizeof(action))]["dodge_msg"];
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n"); 
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������ϰ���½�����\n");
        me->add("kee", -30);
        me->add("force",-5);
        write(HIB"�����Ĳ��Ļ�����...����������������...\n"NOR,me);
        return 1;
}
string perform_action_file(string func) {
       return CLASS_D("linghai") + "/fenxin-blade/" + func;
}


