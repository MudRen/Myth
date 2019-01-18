//���±޷� by cigar 2002.01
inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N�������ܣ�һʽ",
        "$N����һ�ϣ�ʹ��",
        "$N��ȻһЦ��һʽ",
        "$N����Ծ��ʹ��",
});
string* skill_tail =({
        "������$w��Ϊһ�������¹����$n��$l��",
        "������$w��������Ӱ����$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ���������¹⡣",
        "��$w���Ҽ缱˦����������΢�����$n$l��",
});

mapping *action = ({
   ([   "action":
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��һ��"+BLINK""+HIM"�����޺ۡ�"NOR"����Ȼ����$n�ĺ���",
     "dodge":     -5,
                "parry":                -10,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":
"����Ծ��$ņ��һ�����¹�ʧɫ��������$N����$w��������Ӱ��"+BLINK""+HIC"[����]"NOR"�ѽ�$n����",
     "dodge":     -15,
                "parry":                -25,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w����һ��������$w������һ��,һʽ"+BLINK""+HIB"[����]"NOR"���ε�Ʈ��$n������",
     "dodge":     -10,
                "parry":                -15,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ����˿������û����������¹⻯��ƬƬѩ������$n����Ʈ������������һ��"+BLINK""+HIW"[�绨ѩ��]"NOR"",
     "dodge":     -10,
                "parry":                -5,
     "damage":     50,
     "damage_type":   "����"
   ]),
   ([   "action":
"ͻȻ֮���¹�ʧɫ��$N�����ϳ�һ�����̹⣬ʹ��һ��"+BLINK""+HIG"�����¡�"NOR"��$w���Ͽռ�˦��󣬶��ػ���$n$l�����������¹⣬�޴�����",
     "dodge":     -20,
                "parry":                -10,
     "damage":     55,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;
   if( (string)me->query("gender") !="Ů��")
    return notify_fail("���±޷���ӯ���ˣ�ֻ��Ů�Ӳ���ѧϰ!!\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("�������������û�а취�����±޷���\n");

//   if( (string)me->query_skill_mapped("force")!= "xxxxx")
//     return notify_fail("���±޷��������xxxxxx��������\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("���������һ�ѱ��Ӳ������޷���\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("zhuyue_perform");
 if( ! me->query_temp("zhuyue_perform"))
      {
     if(me->query("skill_zhuyue-whip")==0) return action[random(5)];
     if(random(2))return action[random(5)];
     m_actions=me->query("skill_zhuyue-whip");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[5];
  }
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("�����������������û�а취��ϰ���±޷���\n");
   me->receive_damage("kee", 25);
   me->add("force", -3);
   write("�㰴����ѧ����һ�����±޷���\n");
   return 1;
}


string perform_action_file(string func)
{
return CLASS_D("youning") + "/zhuyue-whip/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("zhuyue-whip",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������±޷�����������ˣ�������±޷�������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����±޷��������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_zhuyue-whip");
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

   if(!arg||arg==" ")arg="���±ޱ�ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIR"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_zhuyue-whip",m_actions);
}
