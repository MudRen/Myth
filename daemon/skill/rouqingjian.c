//��ָ���齣
//С��Ů���⹥������
//by junhyun@sk
//

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$Nһ��"+HIW"���������¡�"NOR"����һ��������ʣ������û��ɵ�����������¶������",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIC"�����絶�"NOR"���ָ��أ����ֳ�����â���£�ֱ��$n̴�д�Ѩ��ȥ",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIG"���޾����ࡹ"NOR"���г�������һ�����޾���������ˮ������������$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"+HIM"����ָ���项"NOR"���еĳ������������ƣ��糤�߰����²������ƿ�֮������",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIR"����ʹĪ����"NOR"��¶��ʹ֮ɫ�����г�������ֱָ�Լ���һ��������$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��"HIM"���������᡹"NOR"�������ˣ��漴�������������г�����������$n��$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 4000 )
                return
notify_fail("�������������û�а취ѧ��ָ���齣��\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("���������һ�ѽ�����ѧ��ָ���齣��\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ���������������\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("����������������Ž�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("quest") + "/rouqingjian/" + func;
}

