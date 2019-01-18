//�����������
//��ԯ��Ĺ���⹥������
//by ivy 2002.2.9
 

inherit SKILL;
#include <ansi.h>

//���̽�� �ɺ����� �����鶯 �����ʳ
//�������� ����δ�� �����ʵ� ���ٻ���

mapping *action = ({
   ([  "action": "$Nһ��"+BLINK""+HIW"�����̽�ס�"NOR",����һ�ͣ�����$w����ֱ��$n��$l",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
([ "action":"ֻ��$N����Ծ��,һ��"+BLINK""+HIY"���ɺ����졹"NOR",������ˮ,һйǧ��,����$nȫ��",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":
"$NƮȻ����,����$w��Ȼͻ��,ɲ�Ǽ���������,�ִ�$wȫ�����Ҫ��,����һ��"+BLINK""+HIB"�������鶯��"NOR".\n",
     "dodge":     0,
     "damage": 35,
     "damage_type":   "����"
   ]),
   ([ "action":
"$N����$wбб��һָ$n,���������������Ѹ��֮��ֱȡ$n��$l,ȴ��һ��"+BLINK""+HIR"�������ʳ��"NOR".\n",
     "dodge":     0,
     "damage": 45,
     "damage_type":   "����"
   ]),
  ([  "action":      
 "$Nһ��"+BLINK""+HIC"����������"NOR",����ָ�죬����̽�ϣ���Ȼ��ͬ���ھ�����ʽ.\n",
     "dodge":     0,
     "damage": 40,
     "damage_type":   "����"
   ]),
  ([   "action": 
"$N����$w������ҵػ���һ����,����$n��$l,ͻȻ����ת����һ����������һ��"+BLINK""+HIM"������δ����"NOR".\n",
     "dodge":     0,
     "damage":     50,
     "damage_type":   "����"
   ]),
  ([ "action": 
"$Nһʽ"+BLINK""+HIM"�������ʵ���"NOR",����$w��ת,��Ϊһ��Ѫ��,��ò����س�����$n��Χ.\n",
     "dodge":     0,
     "damage":     30,
     "damage_type":   "����"
   ]),
   ([ "action": 
"$N��������Ծ��,�������ּ�ת,�ε�$nͷ��Ŀѣ,����һ��"+BLINK""+HIG"�����ٻ�����"NOR".\n",
     "dodge":     0,
     "damage":     35,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("�����������,û�а취�������������.\n");

//   if( (string)me->query_skill_mapped("force")!= "jiuyin-force")
//     return notify_fail("����������������������澭������.\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ�������������\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry"|| usage=="throwing";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_qinghu-jian");
     if(me->query("skill_qinghu-jian")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
    return notify_fail("���������������,û�а취��ϰ�����������.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
//  write("�㰴����ѧ����һ�������������.\n");
   return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("gumu") + "/qinghu-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("qinghu-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��������������������ˣ�����������������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û
��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬����������������һ���µ��÷���\n"NOR
);
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

   m_actions=me->query("skill_qinghu-jian");
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

   if(!arg||arg==" ")arg="���������ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qinghu-jian",m_actions);
}
 

