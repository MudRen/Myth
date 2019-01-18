//�Ϻ����� �Ͷ���� buddha-stick
//by junhyun@sk_sjsh
//2002.5.11

inherit SKILL;
#include <ansi.h>;
string* skill_head =({
        "$N������ţ�ʹ��һ��",
        "$N�����ķ���ƽƽһ��",
        "$N����һת����Ȼһ��",
        "$N���˷�����ͻȻһ��",
        "$N�Թ�����������һ��",
        "$N�Ų�������һ������",

});

string* skill_tail =({
        "������$w�ƿ�֮������������$n�ҽ�������",
        "������$n������ԼԼ��������������",
        "��Խ��$n��࣬����$w�籩������$n",
        "��Ӳ������$n��໬��������$wɨ��$n��$l",
        "����������$n�����Ѩ�����$n��æ����",
        "������$w��������Ӱ�ӣ��Ӱ���л���$n",
});

mapping *action = ({
        ([      "name":                 "�ҷ�ȱ�",
                "action":
"$N������ţ�ʹ��һ��"+BLINK""+HIY"���ҷ�ȱ���"NOR+"������$w�ƿ�֮������������$n�ҽ�����",
                "dodge":                5,
     "parry":   -10,
                "damage":               65,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��շ�ħ",
                "action":
"$N�����ķ���ƽƽһ��"+BLINK""+HIY"����շ�ħ��"NOR+"������$n������ԼԼ��������������",

                "dodge":                0,
     "parry":     0,
                "damage":               55,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N����һת����Ȼһ��"+BLINK""+HIY"���������꡹"NOR+"��Խ��$n��࣬����$w�籩������$n",
                "dodge":                10,
     "parry":   -20,
                "damage":               75,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����ǻ�",
                "action":
"$N���˷�����ͻȻһ��"+BLINK""+HIW"�������ǻ���"NOR+"��Ӳ������$n��໬��������$wɨ��$n��$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ͷ�ǰ�",
                "action":
"$N�Թ�����������һ��"+BLINK""+HIB"����ͷ�ǰ���"NOR+"����������$n�����Ѩ�����$n��æ����",
                "dodge":                -5,
     "parry":     -5,
                "damage":               60,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�Ⱥ��ն�",
                "action":
"$N�Ų�������һ������"+BLINK""+HIB"���Ⱥ��նɡ�"NOR+"������$w��������Ӱ�ӣ��Ӱ���л���$n",
                "dodge":                5,
     "parry":   -10,
                "damage":               50,
                "damage_type":  "����"
        ]),   

});


int valid_learn(object me)
{
        object ob;
     if( (string)me->query_skill_mapped("force")!= "lotusforce")
     return notify_fail("�Ͷ���������Ϻ����ӵ������ķ���������\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���Ͷ������
����Щ���������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�����������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   mapping* m_actions;
   i=me->query_temp("QJB_perform");
   if( !me->query_temp("QJB_perform")) {
     if(me->query("skill_buddha-stick")==0) 
          return action[random(6)]; 
          if( random(4) == 1 ) 
          return m_actions[random(sizeof(m_actions))]; 
          else 
              
             return action[random(6)]; 
   }else {
     return action[i];
   }
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�Ͷ������\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
//        write("��Ĭ���ţ���ϰ��һ���Ͷ������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/buddha-stick/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("buddha-stick",1);       
   
   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"����Ͷ��������������ˣ�����Ͷ����������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬���Ͷ�����������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_buddha-stick");
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

   if(!arg||arg==" ")arg="�Ͷ��������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_buddha-stick",m_actions);
}




