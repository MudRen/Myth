//�粨ʮ���� fengbo-cha.c

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
#include <ansi.h>

string* skill_head =({
        "$Nһ��",
        "$N˫��һ�𣬷���һ��",
        "$Nһ������ʹ��һ��",
        "$Nһ��������Х��ʹ��",
        "$Nʹ��",
        "$N��$n����֮�ʣ�һ��",
});

string* skill_tail =({
        "������$w�д��ż������������ͷ�����ؾ���$n���˹�ȥ��",
        "����$n��ͷ�����Ĵ��˹�ȥ��",
        "������$wбб�ش���$n��$l",
        "������$wһ���ɨ��ֱ��$n",
        "��ֱ���$n�ڽں��ˡ�",
        "������$wƮ�첻����$n��ʱ��æ���ң�",
});

mapping *action = ({
        ([      "name":                 "�������ѳ˻ƺ�ȥ��",
                "action":
"$N�ƺ���Ѱ��Щʲô������$w����ǰ��̽�����档\n"
"�����ָ֮��������$n��$l��ԭ����"BLINK+HIY"�������ѳ˻ƺ�ȥ��"NOR,
                "dodge":                0,
		"parry":		0,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n�Ӷ�$W������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���˵ؿ���ƺ�¥��",
                "action":
"$N���β���������$w��һ��"BLINK+HIR"���˵ؿ���ƺ�¥��"NOR"��\n"
"����$n��$l�������ƺ���Ϊ������Ӳ�������������ˮ��������������",
                "dodge":                0,
		"parry":		0,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���ƺ�һȥ��������",
                "action":
"$N�����������䣬�������ߣ�$næ��׷������������ʱ��\n"
"$N�ڿ���ͻȻ����һʽ"BLINK+HIC"���ƺ�һȥ��������"NOR"ֱָ$n��$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$nһ������$W����$N������һ���������ݿ����ɡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������ǧ�ؿ����ơ�",
                "action":
"$Nһ����Х�����������Ӱ�����������ƣ��ŵ�$n�ۻ�����\n"
"����"BLINK+HIW"������ǧ�ؿ����ơ�"NOR"��Ϊ���񣬹�Ȼ��һ��ǰ�������ˣ��󲻼����ߵ�����",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n��$W��÷��겻͸��$N����֮��ֻ�û��С�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���紨������������",
                "action":
"$N����$wһ������һ��"BLINK+HIM"���紨������������"NOR"��Ѹ���ޱȵ���$n�������Ҹ���һ��",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n������$W���˸�Բ���������������������ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���������������ޡ�",
                "action":
"$Nʩ��һ��"BLINK+HIG"���������������ޡ�"NOR"��ֻ��$w�������޵�һ̽��\n"
"��ȥ���ƺ�����$n������紦������֪���ģ�ת˲�����ѵ���$l",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n�������ؾٲ�һ�����ƺ��������ġ����ȵ����˱����ཻʱ��\n"
"$n$W�Ϻ�Ȼ����һ����������$N���˿�ȥ��\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "����ĺ��غδ�ȥ��",
                "action":
"$N��Цһ��������$w�������ذ�Ӱ������һ����Ũ������$n��\n"
"$n����͸����"BLINK+HIB"����ĺ��غδ�ȥ��"NOR"����·��ʵ�ڲ�֪����м�",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n���ܲ��ã�ͦ$W����ǰ�մ��������档���п���ƽƽ���棬ȴ��ƽ���н�$N�Ĺ��Ʒ����ˡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "���̲�����ʹ�˳",
                "action":
"$n�մ���һ����ȴ��$N����һ�����Ѿ���Ӱȫ�ޡ�$n��δ���ü�ת��\n"
"$N��$w�ѵ������ˡ�����"BLINK+YEL"���̲�����ʹ�˳"NOR"��Ȼ����ޱȣ����˷���ʤ��",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"����",
		"parry_msg":
"$n�ۼ�$N����������æ��һ�С��̲�����ʹ�˳����ת��Ȧ����$N��������һ�ߡ�\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "�����������ˡ�",
                "action":
"$Nŭ߳һ��������$w����ޱȵ���$n��ǰ�����ػ������߻���\n"
"����"BLINK+WHT"�����������ˡ�"NOR"����޷���$nʵ�ڲ�֪�������飬������ʵ",
                "dodge":                5,
		"parry":		-15,
                "damage":               50,
                "damage_type":  	"����",
		"parry_msg":
"$n��������$W��ֻ����������һ�����죬���ڽ�$N���˻�ȥ��\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "��������������",
                "action":
"$N����$w�������˸�ԲȦ����һ��"BLINK+CYN"��������������"NOR"������$n��$l��ȥ",
                "dodge":                5,
		"parry":		-5,
                "damage":               55,
                "damage_type":  	"����",
		"parry_msg":
"$n�ƺ����г���ͦ����������ԲȦ��$N����͸$n�����ƣ���Ȼ����óȻ������\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "������һҶ�ۡ�",
                "action":
"$N����һ���������������$w�����³�֮�ƣ�һ��"BLINK+MAG"������һҶ�ۡ�"NOR"ֱ��$n��$l",
                "dodge":                10,
		"parry":		-10,
                "damage":               55,
                "damage_type":  	"����",
		"parry_msg":
"$n��׼���ƣ���$W��$N�ı����͵㡣ֻ����������һ�����죬��Ȼ��$N�ı��е��˿�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "����û�粨�",
                "action":
"$NͻȻ��������һ�ԣ���������֮������������$n����ʱ��\n"
"$N��������������档����"BLINK+GRN"����û�粨�"NOR"�����ײ淨�ľ��裬\n"
"ʩ���������������Ī�⣬�����ƾ��ˣ�$n��ʱ��֪����",
                "dodge":                -5,
		"parry":		-5,
                "damage":               60,
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
    if (me->query("class") != "dragon")
	return notify_fail("������壬����ϰ����ˮ�г�û�Ĳ淨��\n");
    if(me->query_skill_mapped("force") !="dragonforce")
	return notify_fail("�粨ʮ���������������ķ����ܷ���������\n");
    if(me->query("kee") < 50) return notify_fail("�������̫��������Ϣһ����ɡ�\n");
    if(me->query("sen") < 50) return notify_fail("������ǲ��壬��������Ҳʲô��ѧ�����ġ�\n");
    if(me->query("force") < 20) return notify_fail("����������㣬�޷���·����档\n");

    me->add("kee", -30);
    me->add("force", -3);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="fork"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_fengbo-cha");
if( !me->query_temp("HTH_perform")) 
{
if(me->query("skill_fengbo-cha")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];
}
else{return action[6];}
    return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill){}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}

string perform_action_file(string func)
{
	return CLASS_D("dragon") + "/fengbo-cha/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("fengbo-cha",1);
   if(m_skill>200&&m_skill%10==0)
   {
   tell_object(me,HIW"��Է粨ʮ�������������ˣ���ķ粨ʮ���������һ���µľ��磡\n"NOR);
   if(random(me->query("kar"))<20)
   {
   tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
   return;
   }
   if(random(me->query("int"))<20)
   {
   tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
   return;
   }
   tell_object(me,HIW"��ͻȻ�������飬�Է粨ʮ�����������һ���µ��÷���\n"NOR);
   tell_object(me,"��Ϊ����ȡһ�����֣�");
   input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_fengbo-cha");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="�粨ʮ�������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIR"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_fengbo-cha",m_actions);
}
