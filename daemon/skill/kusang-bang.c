//Cracked by Roath
//����ɥ����kusang-bang.c

/*
��ɥ��    dodge  0    parry  -10    damage  25
��ɥ��������ף����ƶ���ƫ�棬���˷���ʤ�������˰���
��������Ϊ�������־������顣
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "��糤��",
                "action":
"$N����һ�����У�����$w��һ��"+HIB"����糤�š�"NOR"�����������$n��$l����ɨȥ",
                "dodge":                15,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "Թ������",
                "action":               
"$N����һת�������ɫ��һ��"+HIB"��Թ�����项"NOR"ʹ����\n����$w����մ����$n��˦Ҳ˦����",
                "dodge":                -15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ҹ����",
                "action":
"$N�趯$w������һЦ��һ��"+HIB"����ҹ���项"NOR"���ŵ���׹�����$n��$l",
                "dodge":                10,
		"parry":		0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ұ��ʳ",
                "action":
"$N��¶����֮ɫ������$wȴ����һ����һ��"+HIB"����Ұ��ʳ��"NOR"�����ޱȵش���$n$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���¶���",
                "action":
"$N��������һ��������$wͻȻ�������ߣ���������֮�⣬\nһ��"+HIB"�����¶��С�"NOR"����ɭɭ��������$n$l",
                "dodge":                -5,
		"parry":		0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l����������"+HIB"��С¥ҹ�ޡ�"NOR"",
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ�����"+HIB"����ճ�����"NOR"�����š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������·",
                "action":               "$N����$wһ�����ó��������⣬����һ��㱼䣬$w��бб�ص�����$n��$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                50,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����ɥ����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�������ɥ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	string name;
	int i;
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
                return notify_fail("�����������������û�а취��ϰ��ɥ����\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ���ɥ����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("kusang-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/kusang-bang/" + func;
}

