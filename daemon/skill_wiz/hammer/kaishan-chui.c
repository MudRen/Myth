
//����ɽ����kaishan-chui.c, weiqi...980307
inherit SKILL;

/*
��ɽ��    dodge  7    parry  -7    damage  27
��ׯ�۹���
*/

void hitagain(object,object,object,int);

mapping *action = ({
        ([      "action":               "$N�Ĺ����߶�ʮһ������$w����$n��ͷ����һ�һ�",
                "dodge":                15,
                "parry":                -10,
                "damage":               35,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "ֻ��$N��ð�׹⣬���͹�𣬳���$w�ͳ�$n��$l����ɨ�˹�ȥ",
                "dodge":                10,
                "parry":                -15,
                "damage":               25,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "ֻ���䣡��һ��$N��$w�ڵ����ҵó������������$N���Ʒ��˸���ͷ������һ����$n���˹�ȥ",
                "dodge":                5,
                "parry":                -10,
                "damage":               35,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "ֻ��$N��һ���������е�$w��������ɨ��Ȧ���Ƶ�$n���˲���",
                "dodge":                5,
                "parry":                0,
                "damage":               20,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "$Nʹ����һ�С��嶡��ɽ�������е�$w�������ᣬ�����転����$n$l������ȥ",
                "dodge":                5,
                "parry":                0,
                "damage":               20,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "����$Nһ��ת������$w���¶���һ����$nֻ��һ���������������\n$n���ڰ��н���֮ʱ��$N��$w����һת�������˻���",
                "dodge":                5,
                "parry":                -10,
                "damage":               25,
                "damage_type":  "����",
                "post_action":          (: hitagain :),
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("str") < 25 )
                return notify_fail("��ɽ��Ҫ��ǿ��׳���ܷ������á�\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취ѧ��ɽ����\n");

        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ�Ѵ��Ӳ���ѧ��ɽ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("str") < 25 )
	        return notify_fail("��ɽ��Ҫ��ǿ��׳���ܷ������á�\n");

        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("������̫���ˣ�ǿ�����档\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�鿪ɽ����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void hitagain(object me, object victim, object weapon,int damage) {
  if (damage!=-2) return;

  //if victim parried out the attack, we attack again...
  
  message_vision("$N������۷��飬��������$n�û�����������\n",victim,me);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}

