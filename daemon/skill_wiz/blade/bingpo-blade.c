//bingpo-blade.c �����Ǻ�����weiqi...97.09.13.
//need ice blade to learn or practice this skill, want check out how 
//to force the use of a ice blade even when use this skill.

/*
���Ǻ���    dodge  -15   parry  5    damage  20
���Ǻ������ص��ǿ죬�����ǵ���һ������ͷ��ء�
��ֻҪ�������ţ����ܷ��أ���Ϊ���Ʋ������޴󰭣�
���Ǻ���������ȡʤ�����˺�����ǿ��
*/

inherit SKILL;

mapping *action = ({
        ([      "name":                 "��",
                "action":
"$N�ḧ���е�$w��ͻȻ��ֻ������һ������������һ����
�����̹ǵĺ�����ȻϮ����$n��$l",
		"dodge":		-15,
		"parry":		5,
		"damage":		15,
		"damage_type":  	"����"
        ]),
        ([      "name":                 "��",
                "action":
"ֻ��$N����$w�����μ��壬������$n����֮�ʣ�
ͻȻ����һ����$n����б������",
		"dodge":		-15,
		"parry":		5,
                	"damage":               	20,
               	"damage_type":  	"����"
        ]),
        ([      "name":                 "��",
                "action":
"$Nб����𣬴���һƬƥ��Ҳ�Ƶĵ������$n��$l",
                	"dodge":                	-15,
		"parry":		5,
                	"damage":               	15,
                	"damage_type":  	"����"
        ]),
        ([      "name":                 "��",
                "action":
"$NͻȻһ���߳������е�$w����һ�������Բ����
�����ĵ����ס��$n��ͷ�����ж���$n�ĺ���",
                	"dodge":                	-15,
		"parry":		5,
                	"damage":               	20,
                	"damage_type":  	"����"
        ]),
        ([      "name":                 "��",
                "action":
"ֻ��$N��ɫһ����һ�С�ǧ����⡹ʹ������ü�ݵ��Ÿ���
$n�����ѪҺ���Ʊ����޾��ĵ��ƶ�ס��������Ҳ�·�Ҫ�����ȥ",
                	"dodge":                	-15,
		"parry":		5,
                	"damage":               	30,
                	"damage_type":  	"����"
        ]),   
        ([      "name":                 "��",
                "action":
"$N���ƽ�������$w�ϴ����ĺ���ȴԽ��ԽŨ��
������ʱ��$n����ͷһ����һ������⻹Ҫ�����ĺ����Ѵ�����$n$l",
               	"dodge":                	-15,
		"parry":		5,
                	"damage":               	20,
                	"damage_type":  	"����"
        ]),   
        ([      "name":                 "��",
                "action":
"$NҲ�������߶�ʮһ���߾�$w�����ؾ���һ����$nӭ��ն�£�
��Ȼֻ��һ�������µĵ���ȴ����Ų����ĺ���������$n��һ����·",
                	"dodge":                	-15,
		"parry":		5,
                	"damage":               	20,
                	"damage_type":  	"����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취�����Ǻ�����
����Щ���������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        ||      (string)ob->query("material") != "ice" )
                return notify_fail("���������һ�ѱ����ĵ����������Ǻ�����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"; //note, should not be able to enable with parry...ice mah:D
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ���Ǻ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����Ǻ�����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

