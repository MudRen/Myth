// bawang-qiang.c ������ǹ����
//modified by bird at /07/13/2004
//Ϊ���ð���ǹ��ת������ѧ


inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N���㾫��ʹ��һ��",
        "$N����һ����һʽ",
        "$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ��",
        "$Nһ���粽��ʹһ��",
		"$Nһ��ǹ��,ʹ��һ��",
});
string* skill_tail =({
        "������$w��������$n���ţ���ɤ��ǰ�ġ�",
        "������$wһͦ����$n$l��",
        "������$w�������ٴ���$n��$l��",
        "������$w��ɣ�������㺮�⡣",
        "������$w����һ�����������¶��ϼ���$n$l",
});

mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIW"��ӭ����������"NOR"������$w��������$n���ţ���ɤ��ǰ��",
                "damage":               50,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ��"+BLINK""+HIG"������Ѱ�ߡ�"NOR"����$n$l",
                "damage":               40,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ���粽��ʹһ��"+BLINK""+HIC"����ɽ��ˮ��"NOR"������$w�������ٴ���$n��$l",
                "damage":               45,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "����"
        ]),
         ([      "action":
"$Nһ��ǹ�ѣ�ž����һ������"+BLINK""+HIM"�����ǹ����"NOR"���������ң�����ʵʵ����$nȫ��Ҫ��",
                "damage":               45,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "����"
        ]),
         ([      "action":
"ֻ��$Nһ��б�磬ʹ��"+BLINK""+HIR"���ٻ������ơ�"NOR"������$w����һ�����������¶��ϼ���$n$l",
                "damage":               55,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����һ��������$w�����벻���ĽǶȴ���$n��$l��\n��һ��"+BLINK""+HIB"�����߳�����"NOR"�������磬�����ޱ�",
                "damage":               35,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"+BLINK""+MAG"������Ͷ���ơ�"NOR"������б�ɣ��Ӳ���ͻ��һǹ������$n$l",
                "damage":               40,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ��"+BLINK""+RED"������ǹ��"NOR"��$wһͦ����$n$l",
                "damage":               50,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
//  ȥ���������ƣ� Ϊ��ת����ѧ
      //  if(me->query("family/family_name") != "������")
    //  return notify_fail("����ǹ���˽���������֮�ܣ�\n");
        if( (int)me->query("max_force") < 100 )
                return
         notify_fail("�������������û�а취������ǹ����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("BWQ_perform");
 if( ! me->query_temp("BWQ_perform"))
      {
     if(me->query("skill_bawang-qiang")==0) return action[random(4)];
     if(random(2))return action[random(4)];
     m_actions=me->query("skill_bawang-qiang");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[4];
  }
   return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
//        write(RED"ʮ��ɱһ�ˣ�ǧ�ﲻ���С�\n"NOR);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("fighter") + "/bawang-qiang/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("bawang-qiang",1);

    if( (int)me->query_skill("bawang-qiang", 1) % 10 == 0 ) 
        {
	tell_object(me, "\n���������ڣ����˵����ˡ�");
            me->add_force(-(int)(me->query_skill("bawang-qiang",1)/10));
           // return; //��ʱȥ������.
//by bird
        }
     // return; 
    ///����ط�����̫�ԣ�modify by bird

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��԰���ǹ������������ˣ���İ���ǹ��������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�԰���ǹ���������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_bawang-qiang");
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

   if(!arg||arg==" ")arg="����ǹ�ش���ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+MAG"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_bawang-qiang",m_actions);
}
