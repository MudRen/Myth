// huoyun-qiang.c ������ǹ����


inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":
"$N���һ��������$w΢�һ��"+HIR"��������ӿ��"NOR"����ʱǹӰ���ǽ��\n"
+"�����ת�ֵ���Ю�����֮�Ʒ���$n",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ��������ǹӰ�Ƚ�����������ס������һ��"+HIR"�����귭�ơ�"NOR"��\n"
+"ֻ����âһ����$w�����������$n",
                "damage":               20,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"+HIR"���������ơ�"NOR"���ߵ���âһ������������ӥ�������������֮�ƣ�"
+"����Ʈ��Ĵ���$n",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "����"
        ]),
         ([      "action":
"$N$wָ�أ����ΰ�����ʹ��һ��"+HIR"��ԡ���ˡ�"NOR"����ǰ��ȥ��\n"+
"ֻ��һ����â�ӹ�����ǹ�������ƵĻ����ռ䣬����$n",
                "damage":               25,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "����"
        ]),
         ([      "action":
"$N΢һ������ʹ��"+HIR"�������ԭ��"NOR"��������𻨣�ֻ�����������\n"+
"$n������һƬ���֮��",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���һ����$w������һ����â��ֻ����������\n"+
"$Nǹ��һ��������"+HIR"�����Ʊ��ա�"NOR"�ݿ����࣬����$n",
                "damage":               15,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N$wһ����ǹӰ���죬$n��ʱ����������"+HIR"����ϼ���졹"NOR"��һƬ���֮��",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N$wһ������$n���´���������һƬ����������"+HIR"��������Ӫ��"NOR"�Ƶ�$n�������ˣ��޴����",
                "damage":               30,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "����"
        ]),
             ([      "action": 
HIR"$N���е�$w"HIR"ֱͦ,����������,�������ķ�,һ��ɱ��������,�����ǳ������⡣"NOR,
                     "damage":              100,
                      "dodge":              -40,
                      "parry":              -40,
                "damage_type":  "����"
        ]),
 });

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("�������������û�а취������ǹ��\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
            int i;
        i=me->query_temp("HYQ_perform");
        if( !me->query_temp("HYQ_perform")) {
                return action[random(7)];
        }else {
                return action[i];
        }
 
//          return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("�㰴����ѧ����һ�����ǹ��\n");
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("yaomo") + "/kusong/huoyun-qiang/" + func;
}


