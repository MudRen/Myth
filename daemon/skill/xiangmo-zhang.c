//����ħ�ȡ�xiangmo-zhang.c by angell
inherit SKILL;

/*
��ħ��    dodge  5    parry  -5    damage  30
ɳɮ��������׾ʵ�ɣ�������ǿ
*/

mapping *action = ({
   ([   "action":     "$N��������������$w��������һ����$n��ͷ����������",
     "dodge":     15,
     "parry":     -5,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "ֻ��$N�����е�$w���������轫�������Ĳ�������һʽ����ˮ��ǧ��ɨ��$n$l",
     "dodge":     -5,
     "parry":     -10,
     "damage":     15,
     "damage_type":   "����"
   ]),
   ([   "action":     "$Nʹ��һ�С�ն����ħ�������е�$w������ն$n",
     "dodge":     10,
     "parry":     -10,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":     "ֻ��$N����$w����һ��������$n����ӭȥ����һ�����˶����ۡ�",
     "dodge":     5,
     "parry":     0,
     "damage":     30,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N���$w���������һ�С�������ˮ��ֱͱ$n��$l",
     "dodge":     0,
     "parry":     0,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��$w����һ����ֱ��$n$l����ʽ���������¡��������ɷ�ͬһ��",
     "dodge":     -10,
     "parry":     -10,
     "damage":     100,
     "damage_type":   "����"
   ]),
});
int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 100 )
     return notify_fail("�������������û�а취ѧ��ħ�ȡ�\n");

   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
     return notify_fail("���������һ�����Ȳ���ѧ��ħ�ȡ�\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="staff"||usage="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("TP_perform");
        if( !me->query_temp("TP_perform") ) {
        return action[random(5)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
     return notify_fail("������̫���ˣ�ǿ�����档\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   write("�㰴����ѧ����һ�齵ħ�ȡ�\n");
   return 1;
}
/*
int valid_effect(object me, object weapon, string name, int skill)
{
}
*/
string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/xiangmo-zhang/" + func;
}
