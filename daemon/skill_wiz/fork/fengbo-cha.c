//�粨ʮ���� fengbo-cha.c
//9-17-97 pickle

/*
�粨ʮ����    dodge  0    parry  -5    damage  25
�������ر�֮���������������Ϊ�еȡ�
*/

//pickle, not changed yet, please try to be compatible. 

// �����ѳ˻ƺ�ȥ���˵ؿ���ƺ�¥
// �ƺ�һȥ������������ǧ�ؿ�����
// �紨��������������������������
// ��ĺ��غδ�ȥ���̲�����ʹ�˳�

// ���������ˣ�����������
// ����һҶ�ۣ���û�粨��

inherit SKILL;

mapping *action = ({
        ([      "name":                 "�������ѳ˻ƺ�ȥ��",
                "action":
"$N�ƺ���Ѱ��Щʲô������$w����ǰ��̽�����档\n"
"�����ָ֮��������$n��$l��ԭ���ǡ������ѳ˻ƺ�ȥ��",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n�Ӷ�$W������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���˵ؿ���ƺ�¥��",
                "action":
"$N���β���������$w��һ�С��˵ؿ���ƺ�¥����\n"
"����$n��$l�������ƺ���Ϊ������Ӳ�������������ˮ��������������",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���ƺ�һȥ��������",
                "action":
"$N�����������䣬�������ߣ�$næ��׷������������ʱ��\n"
"$N�ڿ���ͻȻ����һʽ���ƺ�һȥ��������ֱָ$n��$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$nһ������$W����$N������һ���������ݿ����ɡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������ǧ�ؿ����ơ�",
                "action":
"$Nһ����Х�����������Ӱ�����������ƣ��ŵ�$n�ۻ�����\n"
"���С�����ǧ�ؿ����ơ���Ϊ���񣬹�Ȼ��һ��ǰ�������ˣ��󲻼����ߵ�����",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n��$W��÷��겻͸��$N����֮��ֻ�û��С�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���紨������������",
                "action":
"$N����$wһ������һ�С��紨��������������Ѹ���ޱȵ���$n�������Ҹ���һ��",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n������$W���˸�Բ���������������������ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���������������ޡ�",
                "action":
"$Nʩ��һ�С��������������ޡ���ֻ��$w�������޵�һ̽��\n"
"��ȥ���ƺ�����$n������紦������֪���ģ�ת˲�����ѵ���$l",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n�������ؾٲ�һ�����ƺ��������ġ����ȵ����˱����ཻʱ��\n"
"$n$W�Ϻ�Ȼ����һ����������$N���˿�ȥ��\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "����ĺ��غδ�ȥ��",
                "action":
"$N��Цһ��������$w�������ذ�Ӱ������һ����Ũ������$n��\n"
"$n����͸���С���ĺ��غδ�ȥ������·��ʵ�ڲ�֪����м�",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n���ܲ��ã�ͦ$W����ǰ�մ��������档���п���ƽƽ���棬ȴ��ƽ���н�$N�Ĺ��Ʒ����ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���̲�����ʹ�˳",
                "action":
"$n�մ���һ����ȴ��$N����һ�����Ѿ���Ӱȫ�ޡ�$n��δ���ü�ת��\n"
"$N��$w�ѵ������ˡ����С��̲�����ʹ�˳��Ȼ����ޱȣ����˷���ʤ��",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"parry_msg":
"$n�ۼ�$N����������æ��һ�С��̲�����ʹ�˳����ת��Ȧ����$N��������һ�ߡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "�����������ˡ�",
                "action":
"$Nŭ߳һ��������$w����ޱȵ���$n��ǰ�����ػ������߻���\n"
"���С����������ˡ�����޷���$nʵ�ڲ�֪�������飬������ʵ",
                "dodge":                5,
		"parry":		-15,
                "damage":               30,
                "damage_type":  	"����",
		"parry_msg":
"$n��������$W��ֻ����������һ�����죬���ڽ�$N���˻�ȥ��\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "��������������",
                "action":
"$N����$w�������˸�ԲȦ����һ�С�������������������$n��$l��ȥ",
                "dodge":                5,
		"parry":		-5,
                "damage":               35,
                "damage_type":  	"����",
		"parry_msg":
"$n�ƺ����г���ͦ����������ԲȦ��$N����͸$n�����ƣ���Ȼ����óȻ������\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������һҶ�ۡ�",
                "action":
"$N����һ���������������$w�����³�֮�ƣ�һ�С�����һҶ�ۡ�ֱ��$n��$l",
                "dodge":                10,
		"parry":		-10,
                "damage":               35,
                "damage_type":  	"����",
		"parry_msg":
"$n��׼���ƣ���$W��$N�ı����͵㡣ֻ����������һ�����죬��Ȼ��$N�ı��е��˿�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "����û�粨�",
                "action":
"$NͻȻ��������һ�ԣ���������֮������������$n����ʱ��\n"
"$N��������������档���С���û�粨������ײ淨�ľ��裬\n"
"ʩ���������������Ī�⣬�����ƾ��ˣ�$n��ʱ��֪����",
                "dodge":                -5,
		"parry":		-5,
                "damage":               40,
                "damage_type":  	"����",
		"parry_msg":
"$n������������$W��������$N����Χκ����֮�ǹ�Ȼ��Ч����$N���˻�ȥ��\n",
		"parry_power":		15,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if (me->query("class") != "dragon")
		return notify_fail("������壬����ϰ����ˮ�г�û�Ĳ淨��\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("��������������޷����粨ʮ����ľ���֮����\n");

	if (me->query_skill("dragonforce", 1) < me->query_skill("fengbo-cha", 1)/2)
		return notify_fail("��������ķ���Ϊ̫�͡�\n");

        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return notify_fail("���������һ����������ѧ�淨��\n");
        return 1;
}

int practice_skill(object me)
{
//    int knowledge=me->query("longgong/�粨ʮ����");
//   int mylev=me->query("fengbo-cha", 1);
//  string msg;

    if (me->query("class") != "dragon")
	return notify_fail("������壬����ϰ����ˮ�г�û�Ĳ淨��\n");
    if(me->query_skill_mapped("force") !="dragonforce")
	return notify_fail("�粨ʮ���������������ķ����ܷ���������\n");
    if(me->query("kee") < 50) return notify_fail("�������̫��������Ϣһ����ɡ�\n");
    if(me->query("sen") < 50) return notify_fail("������ǲ��壬��������Ҳʲô��ѧ�����ġ�\n");
    if(me->query("force") < 20) return notify_fail("����������㣬�޷���·����档\n");

    me->add("kee", -30);
    me->add("force", -3);
//    msg="$N�����ػ���ϰ�ŷ粨ʮ���棬�ƺ���Щ������\n";
/*    if (knowledge != 1 && knowledge !=2) knowledge = 0;
    if (knowledge==1 || !knowledge)
        msg+=action[mylev/20]["name"];
    if (knowledge==2)
	msg+=action[mylev/15]["name"];
    msg+="��һ�С�\n";
    msg+="mylev is "+mylev;
*/
//    message_vision(msg, me);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="fork"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
string query_parry_msg(object weapon)
{
    return action[random(sizeof(action))]["parry_msg"];
}
string perform_action_file(string func)
{
return CLASS_D("dragon") + "/fengbo-cha/" + func;
}
