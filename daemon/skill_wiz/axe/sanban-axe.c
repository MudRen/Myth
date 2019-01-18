// ������������, sanban-axe
// updated 6-16-97 pickle
 
/*
���師    dodge  20    parry  -15    damage  35
���師������������˷���ʤ��������ʹ���師����Զ��
�ζ�Ϊ�á�����ÿ���������ޣ�һ�����У�ɱ�˾޴�
*/

inherit SKILL;
void takeforce();
mapping *action = ({
        ([      "action":
"$N��һ�������ϡ�������$w������һ�������֮�ƣ���$n��ͷ����",
                "damage":               45,
                "dodge":                20,
                "parry":                -15,
                "damage_type":  	"����",
		"name":			"����",
//		"post_action": 		(:takeforce:),
        ]),
        ([      "action":
"$N��һ������������˳�ƴ����󸫣���$nһ�֮�ʣ��Ը�β���ֵ���$n���ż���",
                "damage":               25,
                "dodge":                20,
                "parry":                -15,
                "damage_type": 		"����",
		"name":			"����", 
//		"post_action": 		(:takeforce:),
       ]),
        ([      "action":
"$N��һ�����Ͷ��䡹����ת��ͷ������$w����һ������������$n���Դ�����",
                "damage":               40,
                "dodge":                20,
                "parry":                -15,
                "damage_type": 		"����",
		"name":			"�Ͷ���", 
//		"post_action": 		(:takeforce:),
        ]),
	([       "action":
"$N��һ����ͱ������$n�����еĿ�϶���Ը�β���ֵ���$n��$l�ݺݴ�����ȥ",
                "damage":               30,
                "dodge":                -20,
                "parry":                15,
                "damage_type": 		"����", //pickle, ���� not deifined.
		"name":			"ͱ", 
//		"post_action":		(: takeforce :),
        ]),
});

int valid_learn(object me)
{
        object ob;
        int forcelev=(int)me->query_skill("lengquan-force",1);
        int axelev=(int)me->query_skill("sanban-axe", 1);
        int basicaxelev=(int)me->query_skill("axe", 1);
	int limit, forcelimit;

	if (me->query("betray/count"))
		return notify_fail("����ѧ֮�Ĳ�ר����Եѧ����������\n");
	if(me->query("family/family_name") != "������")
		return notify_fail("���������˽���������֮�ܣ�\n");
        if( (string)me->query_skill_mapped("force")!= "lengquan-force")
	return notify_fail("���������������Ȫ�񹦲ſɷ���������\n");
        limit=axelev;
        if(forcelimit<30 || (string)me->query("gender")=="����")
	forcelimit=30;
	if(limit < 200) {
        	if(forcelev<limit)
			return notify_fail("����ڹ������㣬�޷����ڹ�����������師�Ĺ��ơ�\n");
        	if(basicaxelev<limit)
			return notify_fail("��ĸ����������������ܾ�ѧ�������������������Լ��ɲ�����ġ�\n");
	}
        if( (int)me->query("max_force") < 200 )
                return notify_fail("��������������޷�����Ӷ�һ���󸫡�\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "axe" )
                return notify_fail("����û�и�ͷ��ô������ʦ�����̵İ����أ�\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="axe") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
    int total=2, current;
    if (me->query_skill("sanban-axe", 1) > 60)
	total=3;
    return action[random(total+1)];
/*    current=me->query("jjf/sanban-axe");
    if (current==total) current=-1;
    me->set("jjf/sanban-axe", current+1);
    return action[current];
*/
}
 
int practice_skill(object me)
{
        object weapon;
 
	if (me->query("betray/count"))
		return notify_fail("����ѧ֮�Ĳ�ר����Եѧ����������\n");
	if(me->query("family/master_id") != "lao ren")
		return notify_fail("�����ʹ������������ȴ��֪�����ϰ��\n");
        if( (string)me->query_skill_mapped("force")!= "lengquan-force")
	return notify_fail("���������������Ȫ�񹦲ſɷ���������\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "axe" )
                return notify_fail("�����޸��������ϰ������\n");
 
        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30)
                return notify_fail("�������������������������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 50);
        me->add("force", -30);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}
 
string perform_action_file(string action)
{
        return CLASS_D("fighter") + "/sanban-axe/" + action;
}
void skill_improved(object me)
{
      if( (int)me->query_skill("sanban-axe", 1) % 10 == 0 ) 
        {
	tell_object(me, "\n���������ڣ����˵����ˡ�");
            me->add_maximum_force(-(int)(me->query_skill("sanban-axe",1)/10));
        }
	return;
}

void takeforce()
{
  object me=this_player();
  int reduce=(int)me->query("max_force")/25;

  if (me->query("force")>reduce)
    me->add("force", -reduce);
  else me->set("force", 0);
}
