//modified by vikee
//2000.10

inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N�����������У�ʹ��һ��",
        "$N�Ĵ����ߣ�һ��",
        "$N��̬���У�һ��",
        "$N�й�ֱ����ͻȻһ��",
        "$N˫��һ�٣���ֱԾ��һ��",
});

string* skill_tail =({
        "������$w��ͣ�ز�����",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "������$wȥ��Ʈ��������ֻ����$n�ۻ�����",
        "������$w�����㺮�⣬ָ��$nǰ��Ѩ��",
});

mapping *action = ({
		([	"name":			"��������",
		"action":
"$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ������"+BLINK""+HIC"���������硹"NOR"��Ȼ���޿ײ���",
		"dodge":		-5,
		"parry":		-10,
		"damage":		 50,
		"damage_type":		"����"
	]),
	([	"name":			"�������",
		"action":
"$N����$w�����㺮�⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l������"+BLINK""+HIM"��������硹"NOR"������ã�ʵ���ѷ�",
		"dodge":		-5,
		"parry":		15,
		"damage":		40,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N��$n�������ߣ�һ��"+BLINK""+HIY"[��������]"NOR",����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
		"dodge":		-15,
		"parry":		10,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"�����п�",
		"action":
"$N��������$w��������㺮�⣬��ס$n���ظ���ֻ��$n��������\n"
"����"+BLINK""+HIR"�������пա�"NOR"ֱ��ϸ�����ܣ�$nʵ�ڲ�֪$w��Ҫָ���Լ����Ϻδ�",
		"dodge":		25,
		"parry":		-10,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"������Ӱ",
		"action":
"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"����"+BLINK""+HIB"��������Ӱ��"NOR"���˶�Ŀһ�¡�$nֻ������һ����$w�Ѵ̵���$l",
		"dodge":		-15,
		"parry":		15,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$wȴͻȻת����$n�����㣡����"+BLINK""+HIG"���������ڡ�"NOR"ȷʵ���Ī��",
		"dodge":		10,
		"parry":		-15,
		"damage":		45,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("���������Ϊ�����������ѧ��Ҳû�á�\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���������к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ�����������߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
//        message_vision("$NĬĬ������һ�����Ȼ������һ����������\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_yujianshu");
     if(me->query("skill_yujianshu")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}
/*mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
*/
string perform_action_file(string func)
{
	return CLASS_D("shushan") + "/yujianshu/"+func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("yujianshu",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"�������������������ˣ�������彣������һ���µľ��磡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬���������������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_yujianshu");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="����������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIW"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_yujianshu",m_actions);
}
 
