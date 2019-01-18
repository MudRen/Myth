//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "Ⱥħ����",
                "action":
"$N����$wһ����һ��"+RED"��Ⱥħ���衹"NOR"�γ�������Ӱ�������������$n��$l��������",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               "$N����һת������һ��������$w��һ�����߰����$n��$l,��һ��"+RED"���������"NOR"",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ٹ�ҹ��",
                "action":
"$N�趯$w��һ��"+RED"���ٹ�ҹ�С�"NOR",ͻȻһ�����壬$wЮ�������������$n��$l",
		"parry":		-20,
                "dodge":                -15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������·",
                "action":
"$N����$wһ�����ó��������⣬����һ��㱼䣬����"+RED"��������·��"NOR"$w��бб�ص�����$n��$l",
		"parry":		-20,
                "dodge":                -20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ӱ����",
                "action":
"$N����$w���Ⱪ����һ��"+RED"����Ӱ������"NOR",�ּ��ֿ����$n$l��ȥ",
		"parry":		-10,
                "dodge":                -20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ع�",
                "action":
"$N��Ȼ������һչ������$wͻ�����߽�â��৵ش�����$n��$l,��һ��"+RED"����ع���"NOR"",
		"parry":		-20,
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ�����"+RED"����ճ�����"NOR"�����š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l����������"+RED"��С¥ҹ�ޡ�"NOR"",
                "dodge":                -10,
                "parry":                -10,
                "damage":               50,
                "damage_type":  "����"
        ]),


});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취��׷�꽣��\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
	string name;
	mapping actions;

        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        actions=action[random(6)];
        }else {
        actions=action[i];
        }

	name=actions["name"];
	me->set_temp("kill_msg","special_msg");
	me->set_temp("special_msg",name);

	return actions;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ׷�꽣��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ��׷�꽣����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zhuihun-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuihun-sword/" + func;
}


