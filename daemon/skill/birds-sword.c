//���񽣷�
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$Nһ��",
        "ֻ��$N��������Ծ��,һ��",
        "$Nʹ��",
        "$NƮȻ������һʽ",
        "$N��������Ծ��,�������ּ�ת��һ��",
        "$N����������һ��",
});

string* skill_tail =({
        "������$w��������,�ó�һ���׹�ֱ��$n��$l",
        "��$w����һ������,������������,ֱȡ$n��$l",
        "���������ּ�ת,�ε�$nͷ��Ŀѣ",
        "������$w��ò����س�����$n��Χ.",
        "��������ˮ������$nȫ��",
        "������$w���������֮��һ������Ⱥ�ۡ�",
});

mapping *action = ({
   ([  "action": "$Nһ�С�����չ�᡹,����$w��������,�ó�һ���׹�ֱ��$n��$l",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
([ "action":"ֻ��$N��������Ծ��,һ�С�ӥ�����ա�,������ˮ,һйǧ��,����$nȫ��",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":
"$NƮȻ����,����$w΢΢���,ɲ�Ǽ������Ž�,�ִ�$wȫ��Ÿ���λ,����һ�С�������졹.\n",
     "dodge":     0,
     "damage": 35,
     "damage_type":   "����"
   ]),
   ([ "action":
"$N��ָ�ᵯ����,$w����һ������,������������,ֱȡ$n��$l,ȴ��һ�С��ۼ�������.\n",
     "dodge":     0,
     "damage": 45,
     "damage_type":   "����"
   ]),
  ([  "action":      
 "$Nһ�С������ƶˡ�,���⻮������ԲȦ,�������,�������.\n",
     "dodge":     0,
     "damage": 40,
     "damage_type":   "����"
   ]),
  ([   "action": 
"$N����$w������ҵػ���һ����,ƽƽ����$n��$l,���ǰ��񽣷�֮��������⡹.\n",
     "dodge":     0,
     "damage":     50,
     "damage_type":   "����"
   ]),
  ([ "action": 
"$Nһʽ���ž���Ѫ��,����$w��ת,��Ϊһ��Ѫ��,��ò����س�����$n��Χ.\n",
     "dodge":     0,
     "damage":     30,
     "damage_type":   "����"
   ]),
   ([ "action": 
"$N��������Ծ��,�������ּ�ת,�ε�$nͷ��Ŀѣ,����һ�С����ﱨ����.\n",
     "dodge":     0,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([ "action": "$Nһ����Х,���ΰεض���,����һ�С���Ӱ������,����ֱ��$nͷ��",
      "dodge": 0,
      "damage": 50,
      "damage_type": "����"
]),
 ([ "action":
 "$N����$wһ��,����ɢ��ʮ�����ɫϼ��,��ס��$nȫ��,����һ�С���ȸ������",
     "dodge": 0,
     "damage": 35,
    "damage_type": "����"
]),
([ "action": "$Nһ�С�����ѧ�ࡹ,����$w��һ�����벻���ķ�λֱ��$n������",
    "dodge": 0,
    "damage": 45,
    "damage_type": "����"
]),
(["action":
 "$N����$wһ��,���طֳ�һ����Ӱ,��������ͬʱ����$n���,���ǡ�ԧ��Ϸˮ��",
  "dodge": 0,
  "damage": 50,
  "damage_type": "����"
]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("�����������,û�а취�����񽣷�.\n");

   if( (string)me->query_skill_mapped("force")!= "ningxie-force")
     return notify_fail("���񽣷�������ϱ�����Ѫ��������.\n");

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
     m_actions=me->query("skill_birds-sword");
     if(me->query("skill_birds-sword")==0 )
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
    return notify_fail("���������������,û�а취��ϰ���񽣷�.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write("�㰴����ѧ����һ����񽣷�.\n");
   return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("yaomo/xueshan") + "/birds-sword/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("birds-sword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��԰��񽣷�����������ˣ���ķ���񽣷�������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û
��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�԰��񽣷��������һ���µ��÷���\n"NOR
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

   m_actions=me->query("skill_birds-sword");
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

   if(!arg||arg==" ")arg="���񽣷���ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_birds-sword",m_actions);
}
 
