//��ħ��
inherit SKILL;
mapping *action = ({
([ "action":  "$N�����ȥ���ұ۴���۵��·���Ȼ����һȭ����һ�������ȭ��",
"dodge":  -20,
"parry": -20,
"force": 60,
  "damage_type": "����",
]),
 ([ "action":  "$N��Ȼ��$n���һָ������������֮ɱ�֡�����ָ��",
"dodge":  -10,
"parry": -10,
"force": 100,
 "damage_type": "����",
                        "weapon": "����",
]),
([ "action":  "$Nһ��ŭ��˫��ƽƽ�Ƴ������ǵ������������Գ����ľ���������ħ��",
"dodge":  0,
"parry": 0,
"force": 160,
"damage_type": "����",
]),
});
int valid_learn(object me)
{
 if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
 return notify_fail("����ħ�Ʊ�����֡�\n");
return 1;
}
int valid_enable(string usage)
{
 return usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}
int practice_skill(object me)
{
if( (int)me->query("sen") < 30)
  return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
if( (int)me->query("kee") < 30 )
  return notify_fail("����������������Ϣһ�������ɡ�\n");
 if( (int)me->query("force") < 10 )
  return notify_fail("������������ˡ�\n");
me->receive_damage("sen", 30);
me->add("force", -10);
return 1;
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/fumozhang/" + func;
}
