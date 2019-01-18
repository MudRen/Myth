#include <ansi.h> 

// ������½���qingyu-sword.c

/*
������½�    dodge  -10    parry  0    damage  20
�˽������������������������ĺ�ʫ�⣬��Ϊ����
������ϲ��
*/

// ��µ��գ�ˮ��й�أ������°�����������
// �ɻ����Σ�˿��������ҹ�꣬�°׷���
// �𲨵�ת, �������

inherit SKILL;

mapping *action = ({
   ([   "name":        "��µ���",
     "action":
"$N��ƮƮ������Ծ������$w�������������⻷����$n��$lȦȥ",
     "dodge":     -15,
     "parry":     10,
     "damage":     20,
     "damage_type":     "����"
   ]),
   ([   "name":        "ˮ��й��",
     "action":
"$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ�����ơ�ˮ��й�ء���Ȼ���޿ײ���",
     "dodge":     -5,
     "parry":     -10,
     "damage":     15,
     "damage_type":     "����"
   ]),
   ([   "name":        "�����°�",
     "action":
"$N����$w�����㺮�⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l�����ơ������°���������ã�ʵ���ѷ�",
     "dodge":     -5,
     "parry":     -5,
     "damage":     25,
     "damage_type":     "����"
   ]),
   ([   "name":        "��������",
     "action":
"$N��$n�������ߣ�����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
     "dodge":     -15,
     "parry":     5,
     "damage":     25,
     "damage_type":     "����"
   ]),
   ([   "name":        "�ɻ�����",
     "action":
"��ս�У�$N��$n��ǰббԾ��������$w��������һ�������$n��$l",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "����"
   ]),
   ([   "name":        "˿�����",
     "action":
"$Nչ�����Σ�$w֮�������಻���ز���$n��$l��\n"
"ʫ�ƣ��ޱ�˿��ϸ��$N�����й�Ȼ���ʫ����ζ",
     "dodge":     -20,
     "parry":     10,
     "damage":     20,
     "damage_type":     "����"
   ]),
   ([   "name":        "����ҹ��",
     "action":
"$N��������$w��������㺮�⣬��ס$n���ظ���ֻ��$n��������\n"
"���С�����ҹ�꡹ֱ��ϸ�����ܣ�$nʵ�ڲ�֪$w��Ҫָ���Լ����Ϻδ�",
     "dodge":     -5,
     "parry":     -10,
     "damage":     20,
     "damage_type":     "����"
   ]),
   ([   "name":        "�°׷���",
     "action":
"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"���С��°׷��塹���˶�Ŀһ�¡�$nֻ������һ����$w�Ѵ̵���$l",
     "dodge":     -15,
     "parry":     15,
     "damage":     15,
     "damage_type":     "����"
   ]),
   ([   "name":        "�𲨵�ת",
     "action":
"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$wȴͻȻת����$n�����㣡���С��𲨵�ת��ȷʵ���Ī��",
     "dodge":     -5,
     "parry":     -15,
     "damage":     25,
     "damage_type":     "����"
   ]),
   ([   "name":     "�������",        
        "action":
HIC "$N���е�$w�й�ֱ�������ⲻס������\n"
"������;����Ȼת�����ϣ�����������½�����һ�С����ͬ�١�!\n"
"���������ޣ�����޷���" NOR,
        "dodge":     -10,
        "parry":     -20,
        "damage":    40,
        "damage_type":     "����"
   ]),  
});
int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 150 )
     return notify_fail("���������Ϊ������޷�ѧ������½���\n");
   if( (int)me->query_skill("zhenyuan-force", 1) < 20)
     return notify_fail("�����Ԫ�񹦻�򲻹����޷�ѧ������½���\n");
   if (!(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ����������ϰ������\n");
   return 1;
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("xiaofeng-sword");

   if (dod<swo/2)
     return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
   if ((int)me->query("kee") < 60)
     return notify_fail("������Ƿ�ѣ�ǿ��������·罣�к����档\n");
   if ((int)me->query("force") < 30)
     return notify_fail("���������㣬ǿ��������·罣���߻���ħ��Σ�ա�\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$NĬĬ������һ�����Ȼ������һ��������½���\n", me);
   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   i=me->query_temp("XFJ_perform");
   if( !me->query_temp("XFJ_perform")) {
     return action[random(7)];
   }else {
     return action[i];
   }
//        return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return CLASS_D("zhenyuan") + "/xiaofeng-sword/"+ action; 
}

