//�ݹǵ���, kugu-blade.c
//modified 4-17-97 pickle

/*
�ݹǵ�    dodge  -5    parry  -5    damage  20
�޵׶�֮ɱ�־�ѧ������רע������ʹ�ô����书���
�ݹǵ����ܷ��ӳ��������������в�����������ͨ�ĵ�
�˺�������
*/
//pickle, haven't changed settings yet, please try to be compatible 
//with above parameters...weiqi.

// ʬ���Ұ����ʬ���⣬ʬɽѪ������ʬ���꣬����ʬ����ʬ��

inherit SKILL;

mapping *action = ({
        ([      "name":                 "ʬ���Ұ",
                "action":
"$N��$n���ܹ�����ȥ������$w���в���$n�����̣�\n"
"���С�ʬ���Ұ����Ȼ��Ч���Ƶ�$n��æ����",
                "dodge":                -10,
		"parry":		-15,
                "damage":               20,
                "damage_type":  	"����",
		"dodge_msg":
"$n�����߰˸������俴���Ǳ�������ȴ����ض����$N�Ĺ��ơ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n�ۼ�����������æ�����£�˳����$W��$N���ϵ�����\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ����",
                "action":
"��ս�У�$N��Ȼ��$w�������ԣ�ֱͦͦ�ĵ��¡�����$n��֪����֮ʱ��\n"
"$N��$w�綾��һ��ͻȻ��$n��$l��ȥ������һ�С���ʬ���꡹",
                "dodge":                -15,
		"parry":		-10,
                "damage":               20,
                "damage_type":  	"����",
		"dodge_msg":
"$N�ƺ��Ѿ�������$nʱ��$nͻȻԭ�ؼ�ת����ΪһƬ��Ӱ�����ˡ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n��æʹһ�С���ʬ���꡹����$Wһ�������Ƽ��˿�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "ʬɽѪ��",
                "action":
"$N����������ɽ����������������$w�����Ŀ�ĺ��⣬����ס$n��ȫ��",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"dodge_msg":
"$nƽƽԾ���ڿ�����ת��Ȧ������$N���ԭ���ǡ�ʬɽѪ������\n",
		"dodge_power":		10,
		"parry_msg":
"$nչ��$W���ӣ��������쵶Ӱ�����С�ʬɽѪ������Ȼ��$N�Ĺ��Ƶ��˻�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ��",
                "action":
"$N��Ȼ����ɫ�԰ף������������ʧ�ںڰ��С�$n�ڼ�ս��ͻȻ�����˵��ˣ�\n"
"����ʧ��䣬$N�����ˡ���ʬ�𼣡��İ��н�����һ����$n�ĺ��Կ�ȥ",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"����",
		"dodge_msg":
"$N�ƺ���Ҫ������$n����$n������Ť���£������Ʊ��˹�ȥ��\n"
"$N��Ȼ����һ�������ȴ���������С���ʬ�𼣡��İ��\n",
		"dodge_power":		10,
		"parry_msg":
"$n��׼���ƣ���$Wӭȥ��ֻ�����ۡ���һ�����룬$n����Ӱ�Ѳ����ˡ�\n",
		"parry_power":		10,
        ]), 
        ([      "name":                 "����ʬ",
                "action":
"ֻ��$N�����Ṧ������һ�����ε�ǽ�ڣ���$n�����ƽ���\n"
"��ת��$N��Ȼһ������$n��$l����һ�С�����ʬ��",
                "dodge":                -10,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"����",
		"dodge_msg":
"$n��֨֨�����������˫��һ�㣬��$Nͷ�����˹�ȥ��\n",
		"dodge_power":		10,
		"parry_msg":
"$nԭ�ز��������������ݰ㼲ת��$N��Ȼ���У�ȴ��$nжȥ������\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ����",
                "action":
"$N�Ż��󿪣�����ɥʧ����־һ�㣬����������е�$w��$n��ȥ��\n"
"���С���ʬ���⡹��Ȼ���գ���������󣬱Ƶ�$n��������",
                "dodge":                10,
		"parry":		10,
                "damage":               40,
                "damage_type":  	"����",
		"dodge_msg":
"$næ��һ�С���ʬ���⡹��ϥ�ǲ��䣬Ӳ�����������£���Ȼ�ܹ���$N��������\n",
		"dodge_power":		10,
		"parry_msg":
"$n�ۼ���������Ȼ���ܲ��ã�������ӭ��ֻ�����ۡ���һ����\n"
"$N�Ľ������а��񣬾�Ȼ��$n����Ӱ�졣\n",
		"parry_power":		10,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if(me->query("family/family_name") != "�ݿ�ɽ�޵׶�")
		return notify_fail("�㲻ϰ��Ѫ�ȣ�ѧ���˿ݹǵ���\n");
        if( (int)me->query("max_force") < 350 )
                return notify_fail("�����������������ѧ�ݹǵ���������Щ���������ɡ�\n");

	if ((int)me->query_skill("kugu-blade")>=me->query("wudidong/sell_reward"))
	    return notify_fail("��Ŀݹǵ��Ѿ����˼��ޣ���Ҫ�����Ѫ����������Ϊ��\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
        return 1;
}

int practice_skill(object me)
{
    if (me->query_skill("kugu-blade", 1) < 180)
        return notify_fail("�����Ϊ�����������ݹǵ���\n");
    if ( me->query("family/master_id") != "yu shu" )
	return notify_fail("ʦ����û�н��������ϰ�ݹǵ��ķ��š�\n");
    if (me->query("kee") < 50)
	return notify_fail("����������㣬�޷����ݹǵ���\n");
    if (me->query("force") < 50)
	return notify_fail("�������̫�ͣ��޷�����Ծ��ͬʱ�赶��\n");
    me->add("kee", -30);
    me->add("force", -30);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="dodge"||usage=="blade"||usage=="parry";
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

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if ((int)me->query_skill("kugu-blade", 1) % 10 == 0 ) {
		tell_object(me, "\n��ͻȻ��������ȱ�˵�ʲô������\n\n");
		me->add_maximum_force(-2);
	}
}

string perform_action_file(string func)
{
	return CLASS_D("yaomo") + "/wudidong/kugu-blade/"+func;
}
