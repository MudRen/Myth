// feitian-jian.c  ���콣
// Modified by Cody May.2001
// Write by Cody


#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "ͻȻ֮�䣬��Ӱ���ϣ�$nɲ�Ǽ���Զȥ����֮�⣬$N��ʱ���˸��ա�\n",
        "$n��������Ȱ�һ�Σ�ͻȻ��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
        "$Nֻ����ǰһ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
        "$n���к��ļӿ죬���к��ı�����ʲ��壬$N��������ʽ��Ȼ͸�������ԭ������һ�߻�Ӱ��\n",
        "ֻ��$n�������һ��������$N����ʽ���Ұڶ�����ʹ��$N������ա�\n",
});


mapping *action = ({
	([	"name":			"������",
		"action":
"ֻ��$N��һ�С�"HIC"������"NOR"����$n������ʩչ����ն��",
                "dodge":                -5,
                "parry":                 -5,
		"damage":		35,
		"damage_type":		"ն��"
	]),
	([	"name":			"������",
		"action":
"$Nʹ����"HIY"������"NOR"�������е�$w���������ն�����������ʯ�齦��$n��$l",
                "dodge":                0,
                "parry":                 0,
		"damage":		45,
		"damage_type":		"����"
	]),
        ([      "name":                 "��׵��",
                "action":
"$N����Ծ��ʹһ�С�"HIB"��׵��"NOR"��������$w���Ⱪ������$n�R�մ�������",
                "dodge":                5,
                "parry":                 10,
                "damage":               50,
                "damage_type":          "����"
        ]),
        ([      "name":                 "˫����",
                "action":
"ֻ��$NѸ�ٰγ�$w��һ�С�"HIG"˫����"NOR"�����������������$n��$l��\n"
"����$N���ðε����϶�����õ�����ȫ�޷�϶�Ĺ�����ֻ�����������صĴ���$n��$l",
                "dodge":                10,
                "parry":                 10,
                "damage":               55,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$N��װ���ٰε���ʵ�����������Ƴ�����һ�С�"CYN"������"NOR"����������$n$l��ȥ",
                "dodge":                10,
                "parry":                 0,
                "damage":               45,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$Nһ�ְ�����һ�С�"HIW"������"NOR"�����¶���ֱ����$n��$l",
                "dodge":                -5,
		"parry":		 5,
		"damage":		40,
		"damage_type":		"����"
	]),
	([	"name":			"������",
		"action":
"ֻ��$N����ܹ�������ͬʱ��һ�С�"MAG"������"NOR"��������ת����������������ֱ��$n��$l",
                "dodge":                -5,
                "parry":                 -5,
		"damage":		40,
		"damage_type":		"����"
	]),
	([	"name":			"������",
		"action":
"$N���ٵ��յ����ɼ��ٵ��յ���������������һʽ��"HIR"������"NOR"��������$n���ܵ�ƽ������",
                "dodge":                0,
                "parry":                 -5,
		"damage":		50,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	if (me->carry_object("/obj/feitian/feitian-book1") || me->carry_object("/obj/feitian/feitian-book2")
              || me->carry_object("/obj/feitian/feitian-book3") || me->carry_object("/obj/feitian/feitian-book4"))
		return notify_fail("���콣�Ƿ����������Ľ�����û�����ǵ�ͬ������ô����ѧѽ��\n");

	return 1;
}

int practice_skill(object me)
{
	int skill;
	skill = me->query_skill("feitian-jian",1);
	if( me->is_fighting() )
        	return notify_fail("�㲻����ս������ϰ��\n");
    	if (me->query_skill("feitian-jian", 1) < 200)
        	return notify_fail("�����Ϊ����������������������\n");
	if ((int)me->query("kee") < 100)
		return notify_fail("������Ƿ�ѣ�ǿ�������������к����档\n");
	if ((int)me->query("force") < 100)
		return notify_fail("���������㣬ǿ���������������߻���ħ��Σ�ա�\n");
	if (me->query_skill("sword",1)<= skill)
        	return notify_fail("��Ļ��������������޷���ϰ�����������ļ��ɣ�\n");
	me->add("kee", -50);
        me->add("force", -50);
//        message_vision("$N���������̣�Ȼ������һ�������������\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage == "sword" || usage == "dodge" || usage == "parry";
}

string query_dodge_msg(string limb,object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
    return CLASS_D("quest") + "/feitian-jian/"+func;
}
