// snowsword. �����ѩ�轣����

/*
���ѩ�轣��    dodge  -20    parry  -10    damage  15
�˽���Ѹ������أ�������ѩ�裬���ּ��Ѷ����мܣ���Ϊ
��������֮Ů����ϲ��
*/

// �������ջ�Ӧפ����������ƽɳ
// �ܻ�Ⱦ����˪�ۣ�˪ӡ������Ҳ��
// ��ɸ���������磬���㸡��Ӱ�ƻ�
// �粨������֦��
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N�������ܣ�һʽ",
        "$Nʹ��",
        "$N��ȻһЦ��һʽ",
        "$Nһ����ת��ʹ��",
});
string* skill_tail =({
        "������$w��Ϊһ���������$n��$l��",
        "������$w��Ϊһ���������$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ�������㺮�⡣",
        "����ʱһ������Ʈ��$n",
});


mapping *action = ({
        ([      "action":
"$Nʹһ��"+BLINK""+HIB"���������ջ�Ӧפ��"NOR+"������$w��Ϊһ���������$n��$l",
                "dodge":                -5,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N������ת��ʹ��"+BLINK""+HIG"����������ƽɳ��"NOR+"��һ�������н���������ɨ��$n��$l",
                "dodge":                -35,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һЦ��һʽ"+BLINK""+HIY"���ܻ�Ⱦ����˪�ۡ�"NOR+"���������Ӱ��$nֻ����������������Ϯ����ȴ��֪���������",
                "dodge":                -10,
                "parry":                -15,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w����һ����һʽ"+BLINK""+HIW"��˪ӡ������Ҳ�ա�"NOR+"�ó�һ�麮������$n��$nֻ����������������ס��",
                "dodge":                -30,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����$w��һ����ֻ�������㣬Ʈ��������\n��һ��"+BLINK""+HIR"����ɸ���������硹"NOR+"ֻ����$n�ۻ����ң����ﻹ���м�",
                "dodge":                -20,
                "parry":                -20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ��أ�����һʽ"+BLINK""+MAG"�����㸡���»ƻ衹"NOR+"",  
                "dodge":                -35,
                "parry":                -5,
                "damage":               40, 
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ܣ�һʽ"+BLINK""+HIC"���粨������֦����"NOR+"����ɫ��ţ����ƴ�����һ��������ˮ�����������Ľ���ֱָ$n��������",
                "dodge":                -5,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$N����$w����һ����һʽ��˪ӡ������Ҳ�ա��ó�һ�麮������$n��$nֻ����������������ס��"NOR,
                "dodge":                -30,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$N����$w��һ����ֻ�������㣬Ʈ������������$n��$l"NOR,
                "dodge":                -10,
                "parry":                -15,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$nֻ����һ�������ӹ���$N����Ȼ��Ʈ��$n��󣬽���ֱָ$n�ĺ���"NOR,
                "dodge":                -30,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "action":
HIW"$Nһʽ���粨������֦��������ɫ��ţ����ƴ�����һ�����������ˮ����������"NOR,  
                "dodge":                -35,
                "parry":                -5,
                "damage":               50, 
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

		if( (string)me->query("gender") !="Ů��")
                return notify_fail("���ѩ�轣ֻ��Ů�Ӳ���ѧϰ!!\n");
    
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����ѩ�轣����\n");

//        if( (string)me->query_skill_mapped("force")!= "moonforce")
//                return notify_fail("���ѩ�轣�������������ɽ��Ů���Բ���ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
		mapping* m_actions;
		m_actions=me->query("skill_smowsword");
        i=me->query_temp("WX_perform");
        if( !me->query_temp("WX_perform")) {
           if(me->query("skill_snowsword")==0) return action[random(7)];
           if(random(2))return action[random(7)];
           m_actions=me->query("skill_snowsword");
           return m_actions[random(sizeof(m_actions))];
        }
		else 
		{
         return action[i];
		}
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 100
        ||      (int)me->query("force") < 30 )
                return notify_fail("�����������������û�а취��ϰ���ѩ�轣����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
//        write("�㰴����ѧ����һ����ѩ�轣����\n");
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("snowsword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��Է��ѩ�轣����������ˣ���ķ��ѩ�轣������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�Է��ѩ�轣�������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_snowsword");
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

   if(!arg||arg==" ")arg="���ѩ�轣��ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_snowsword",m_actions);
}
