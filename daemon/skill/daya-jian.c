// daya-jian.c
//  ���Ž���

#include <ansi.h>
#define OO YEL"���Ž���"NOR
inherit SKILL;

mapping *action = ({
    ([  "action": 
"ֻ��$N����$w�趯��һƬ��״��ʹ��"OO"��һʽ�����̸�ʽ����\n"
"��$n��Χ������ס��\n",
        "parry_msg" :
"$nʹ�������㡱�־�����������������µ�����ܾ��գ���ʱ�仯���ܾóɡ�\n"
"ֻ��$n˿�����ң�Ӧ�Ӳ�Ͼ����$N����ʽһһ��ס��",
"parry_power":          10,
 //       "jibie" :15,
        "dodge" :-20,
        "parry" :-30,
        "zhaoshi":"���̸�ʽ��",
        "damage":90,
        "damage_type":"����"    ]),

    ([  "action":
"ֻ��$N����$w�Ӷ�һ�ɰԵ��Ľ���������"OO"�ڶ�ʽ��������ʽ����\n"
"����$n����б������Ȼ�з硣",
        "parry_msg"  :
"$nʹ�������ݡ��־���������������յ�λ��Ӧ����ʱ��Ҳ��\n"
"$n�����������������ɵ�Ծ����",
"parry_power":          10,
//        "jibie" :30,
        "dodge" :-10,
        "parry" :-10,
        "zhaoshi":"������ʽ��",
        "damage":80,
        "damage_type":"����" ]),
    ([  "action":
"ֻ��$N����$w������㽣�⣬����һ�ߣ�����"OO"����ʽ��������ʽ����\n"
"$w�������ߣ���$n��ǰ���衣",
        "parry_msg"  :
"$nʹ�������͡��־���������������������ͣ���־��Ҳ��\n"
"$n�ƺ���Щɢ�ң�����ͻȻ��ס����ʱ��$N�Ĺ��ƻ��������Ρ�",
"parry_power":          10,
//        "jibie" :45,
        "dodge" :-10,
        "parry" :-20,
        "zhaoshi":"������ʽ��",
        "damage":90,
        "damage_type":"����"    ]),
    ([  "action":
"ֻ��$N�趯����$w������"OO"����ʽ��������ʽ����\n"
"�������֮�У���һ�����벻���ĽǶ�ͻȻ����һ������$n�����ֱ�̡�",
        "parry_msg"  :
"$nʹ��������־��������������������˵�����������\n"
"$n��ǧ��һ��֮�ʣ�ͻȻ��֪��ʲô�ط����һ������ס��$N����һ�С�",
"parry_power":          10,
//        "jibie" :60,
        "dodge" :-10,
        "parry" :-30,
        "zhaoshi":"������ʽ��",
        "damage":80,
        "damage_type":"����"    ]),
        ([      "action":
"ֻ��$N����$w��������֮����������ͣ���������������������"OO"\n"
"����ʽ�������ʽ��������ֱ��$n���̹�ȥ��",
                "parry_msg" :
"$nʹ�������ȡ��־������������������ȡ˳��\n"
"$n��ͷ���$N��һ�У�����Ծ����",
        "zhaoshi":"�����ʽ��",
"parry_power":          10,
//        "jibie":75,
        "dodge":-15,
        "parry":-40,
        "damage":60,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$N������ԭ�����ߣ��Ų�ɢ�����ң�����"OO"����ʽ��������ʽ����\n"
"����$w�ڶ�����ʱ��$n�̳�һ����",
                "parry_msg" :
"$nʹ�������衱�־���������������ս������ݣ����岻�����ӡ�\n"
"$n��ƫ��ƫ��ǡǡ��$N�Ĺ����ж��˿�ȥ��",
        "zhaoshi":"������ʽ��",
"parry_power":          10,
//        "jibie":90,
        "dodge":-20,
        "parry":-20,
        "damage":100,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$N����ʮ�����أ�����"OO"����ʽ��������ʽ����\n"
"����$w�������ޣ���������һ������$n�ļ粿���˹�ȥ��",
                "parry_msg" :
"ֻ��$N����ʮ�����أ�����$w�������ޣ���������һ����\n"
"$n��æ���л��ء�",
        "zhaoshi":"������ʽ��",
"parry_power":          10,
//        "jibie":105,
        "dodge":-30,
        "parry":-20,
        "damage":120,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$Nʹ��������"OO"�ڰ�ʽ����ֹ�ʽ����\n"
"����$w������ͣ������з���֮������$n����ӿȥ�����˶����˱�֮�⡣",
                "parry_msg" :
"����$w������ͣ������з���֮�����������������˱�֮�⡣",
        "zhaoshi":"��ֹ�ʽ��",
"parry_power":          10,
//        "jibie":120,
        "dodge":-10,
        "parry":-50,
        "damage":100,
        "damage_type":"����"
        ]),
});

string *daya= ({
"$N���ſھ�����꫸꣬��󼹭ʸ������ܲ�£�����ʱ�ġ�\n",
"$N���ſھ��������ڸ٣��������ɡ�\n",
"$N���ſھ�������������֮������\n",
"$N���ſھ������ܾ�����������ġ�\n",
"$N���ſھ����ս���ʵ�Թ⣬������¡�\n",
"$N���ſھ�������ɪ�����۴�ʦ��\n",
"$N���ſھ���־�ڵ������ڵ£������ʣ������ա�\n",
"$N���ſھ����������ʣ�ԨԨ��Ԩ���ƺ����졣\n"
});

int practice_skill( object me )
{
        string msg;
                object target;
//
                if ((int)me->query_skill("daya-jian", 1) < 300)
        return notify_fail("���ŹŽ�����Ϊ̫��,���޷������侫�衣\n"); 
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 50 )
                return notify_fail("�����������������û�а취��ϰ���ŹŽ�����\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
    if( me->query("max_force")<2000 )
        return notify_fail("��������������ϰ�˽�����\n");
    if (me->query("mark/dayagett")!= 1)
        return notify_fail("��δ��������ŹŽ���,��ôҲ�㲻����\n"); 
//        message_vision(daya[random(sizeof(daya))], me, target);
    return 1;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("daya-jian", 1) > 700)
         return notify_fail("���ŹŽ���ֻ�ܿ��Լ����������\n"); 
     return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
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
        return CLASS_D("quest") + "/daya-jian/"+func;
}

