// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//�����촸��??

/*
  dodge  15    parry  -15    damage  30
�䴸��ֱ��ֱȥ������Ϊʵ���ƴ����ͣ��мֵܵ�
��Ϊ���ף�һ���������˺����󡣵������ǲ�����
ӯ��
*/

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
        "������$w�д������װ����������ͷ�����ؾ���$n����������",
        "����$n��ͷ����������������",
        "������$wбб������$n��$l",
        "������$wһ���ɨ��ֱ��$n",
        "��ֱ���$n�ڽں��ˡ�",
        "������$wƮ�첻����$n��ʱ��æ���ң�",
});
mapping *action = ({
   ([   "action":   "$N����$wһת������һ��ǿ���ķ�������$n��$l��
��һ���ּ����ͣ��ƴ����ݣ��ۼ��͵���$n��ǰ",
     "dodge":   10,
     "parry":   -10,
     "damage":   30,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N˫��һ������$w�д������װ����������ͷ�����ؾ���$n���˹�ȥ",
     "dodge":   15,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N��$w�߾ٹ��磬�����������׼$n��$l��������һ��",
     "dodge":   20,
     "parry":   -20,
     "damage":   35,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N�������飬����$w���Ϻ��£�����׽������ȥ·��
����$nһ��㱼䣬��ৡ�������$n��$l",
     "dodge":   0,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$n����֮������ת$w�����Ѵ�����$n��
��һ���������о��������Ϣ�ĵ�����$n��$l",
     "dodge":   10,
     "parry":   -10,
     "damage":   20,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$w�ͻ��˸���Բ�����������ɳ�����
��$n���ܱ���֮�ǣ�����$wбб������$n��$l",
     "dodge":   20,
     "parry":   -25,
     "damage":   30,
     "damage_type":   "����",
   ]),
(["action" : "$Nһ��������Х,��ֱ��$n�Ҽ磬���к��޻���,��ʤ�������ۻ룬
�ഫԴ���̹ſ���ʱ���õĻ���һ�ơ�",
    "dodge" : 20,
    "damage" : 200,
    "lvl" : 120,
    "skill_name" : "����һ��",
    "damage_type" : "����"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����촸��\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ���󴸲��������촸��\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_huntian-hammer");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_huntian-hammer")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];

} else {
return action[6];
}

      return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("�����������������û�а취��ϰ���촸��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����촸��\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("dragon") + "/huntian-hammer/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("huntian-hammer",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��Ի��촸����������ˣ���Ļ��촸������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�Ի��촸�������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_huntian-hammer");
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

   if(!arg||arg==" ")arg="���촸����"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_huntian-hammer",m_actions);
}

