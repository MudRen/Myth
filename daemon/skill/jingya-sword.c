
// Just because the "KEE" propertiy of a character in XLQY is low��
// I make it to prevent some players use one instict to kill others.
// 
// Jingya-sword. �����Ž�����
// Written by vikee for XLQY-ZQ station
// 2000-12-5 17:40


//���Ž���    dodge  -10    parry  -10    damage  15
//�˽���Ϊ��̫����ʫ����ʱ�������Ϊ��ɽ��������ң�����
//�˽������ְ�ʽ����ϰ����Ѫ��Ϊ�����洦��

#include <ansi.h>


inherit SKILL;

mapping *action = ({
	([	"name":			"��",
		"action":
"$Nһ�����е�$w�����г�ŵ������ѣ����������졣˲��̳�������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -20,
		"damage":		5,
		"damage_type":		"����"
	]),
	
	([	"name":                 "��",
		"action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾������������������������ǧ�꣬�����غ�ͨ���̡����е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N����$w�������������⻷��һ����������$n��ǰ̤��һ���������������������ȥ��������������$N���ֽ�ָ�Ѵ���$n��$l",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһת������$n����ͷ��������ͷ�����£���ͷ˼���硣����$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N�������е�$w����Х���裺����ֱ����ǧ�ߣ�������������졣���϶��£�����$n��$l",
		"dodge":		0,
                "parry":                -10,
		"damage":		25,
		"damage_type":		"����"
	]),
        ([      "name":                 "��",
		"action":
"$N����һ�࣬���е�$wƽ�Żӳ�������������������ñ���谮�����ˡ�����$n��$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":      		15, 
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
		"action":
"$N��ǰ̤���벽������$w�й�ֱ�����������������������ᣬ���������ơ�����$n��ǰ��",
                "dodge":                -10,
                "parry":                0,
                "damage":     		20,
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
                "action":
"$N˫��һ�٣���������������ߣ�����֮���á������ߣ��ٴ�֮���͡�������գ�ͷ�½��ϣ�����$w����$n��ͷ��",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":  	"����"
        ]),
});

int valid_learn(object me)
{
	
	object ob;
	
	if( me->query("family/family_name")!="��ɽ����")
		return notify_fail("�����ɽ���ɵ��ӣ�������ᾲ�Ž����İ���֮����\n");
	
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����Ž�����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage=="literate";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
	int sword_level=(int)me->query_skill("sword");
        int pot=random(2)*random(2)*random(2)*random(2)*random(2);
	//��ϰ����1/(2*2*2*2*2)�Ļ����Ǽ���Ѫ.
	if( me->query("family/family_name")!="��ɽ����")
		return notify_fail("�����ɽ���ɵ��ӣ�������ᾲ�Ž����İ���֮����\n");

	if( (int)me->query("sen") < 20
	||	(int)me->query("force") < 300 )
		return notify_fail("��ľ���������������û�а취��ϰ���Ž�����\n");
	
	if (me->query("max_kee")*1000 > me->query("combat_exp")) 
		tell_object(me, "�����ѧ��Ϊû�����������Ž����Ѿ�����������Ѫ�ˣ�\n");		
	
	me->receive_damage("sen", 15);	
	me->add("force", -5);	
	message_vision(MAG"$N�����Լ���ѧʶ��ĬĬ��ϰ��һ�龲�Ž�����\n"NOR,me);
	
	if (me->query("jingya/addpot")==0)	
	  me->set("jingya/addpot",1);
		
		
	if (	me->query("max_kee") < sword_level*10  			//c1. ��ѪС�� ��Ч����*10 
		&& sword_level >175					//c2. ��Ч����>175	
		&& (me->query("max_kee")*1000 < me->query("combat_exp"))//c3. ��Ѫ * 1000 < ��ѧ 		
		&& pot!=0)
		{
		 me->add("max_kee",pot);
		 me->add("eff_kee",pot);			 
                 tell_object(me, "��е���Ϣ��˳����������֫�ٺ����ƺ���Ѫ�������棡\n");
                 me->add("jingya/addpot",pot);               
		}
	
	return 1;
}
