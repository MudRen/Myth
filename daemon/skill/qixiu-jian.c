
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// qixiu-jian.c, �����޽���
// edited 4-16-97 pickle

/*
���޽���    dodge  5    parry  -10    damage  25
���޽���Ϊƴ��������ֻ���˵У���������Σ������
ͻ��֮����ǿ��Ȼ�������Ҵ�һ���������Ӷ�������
*/

// �����ʬ�����ײ��ϣ��������̣�
// �˷����꣬����һ����ʮ�����

#include <ansi.h>;
inherit SKILL;
void set_busy();

string* skill_head =({
        "$N����һ����ʹ��һ��",
        "$N�������ܣ�һʽ",
        "$N����Ծ��һ��",
        "$N����ǧ��һʽ",
        "$N�緢��һ�㣬ʹ��һ��",
        "$Nһ�����У�����һʽ",
});

string* skill_tail =({
        "������$w����$n��ȫ��",
        "������$w����������⣬��$n�����ŵ�ȥ��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��âֱ��$n",
        "�����������ٳ���ʵ���ܲ���͸",
        "��$w����ɱ����$n��������",
});

mapping *action = ({
    ([
      "action":
"$N����һ����$w���⻯Ϊ����׹⣬�ֱ���$n���ʺ����Ҽ硢�����ҽ��󼲴�",
      "dodge":     0,
      "parry":           0,
      "damage":     30,
      "damage_type":   "����",
      "name":     "�������ʬ��",
      ]),
    ([
      "action":
"$N�ؽڽ�Ӳ������$w��һ������һ�������ɨ��\n"
"$nʶ������"+BLINK""+HIW"�����ײ��ϡ�"NOR"����������æ��ܲ���",
      "dodge":     10,
      "parry":     -20,
      "damage":     40,
      "damage_type":   "����",
      "name":     "�����ײ��ϡ�",
      ]),
    ([
      "action":
"$N����Ծ������$w����������⣬��$n�����ŵ�ȥ��\n"
"����"+BLINK""+HIB"���������̡�"NOR"��Ȼ��$n�Ƶ���æ����",
      "dodge":     5,
      "parry":          -10,
      "damage":     30,
      "damage_type":   "����",
      "name":      "���������̡�",
//      "post_action":   (:set_busy:),
      ]),
   
    ([
      "action":
"$N�ܲ���������$w���籩�����$n������\n"
"����"+BLINK""+HIM"���˷����꡹"NOR"��Ȼ¶�����ɿ��ţ���$nҲ���Ҳ�������Σ��óȻ����",
      "dodge":     5,
      "parry":           -5,
      "damage":     40,
      "damage_type":   "����",
      "name":      "���˷����꡹",
//      "post_action":   (:set_busy:),
      ]),
    ([
      "action":
"$N���˴���������$n��$l����������"+BLINK""+HIR"������һ����"NOR"
������$n��$N���˾Ϳ��Ŵ󿪣������׸���",
      "dodge":     10,
      "parry":           -10,
      "damage":     45,
      "damage_type":   "����",
      "name":      "������һ����",
//      "post_action":   (:set_busy:),
      ]),
    ([
      "action":
"$N���潣�ߣ�Ѹ�����׵���$n��Χ��Ȧ��\n"
"$nֻ����Χ������Ӱ����ʱ���п�����һ��$w�����벻����\n"
"λ�ô�����ʵ����Σ������",
      "dodge":          0,
      "parry":     -15,
      "damage":     35,
      "damage_type":   "����",
      "name":      "��ʮ�������",
      ]),
  ([ "name": "��������졹",
     "action":
MAG"$N����ǧ,���е�$w"+MAG"��ó�ǧ����Ӱ,ֱ��$nȫ��,ʹ$n�ѱ�ֱ��!!\n"
"$n����æ���Ҽ�,һ��ī��������Ϣ��ֱȡ�Ժ�����Ѩ,$nȴľȻ����!"NOR,
     "dodge": -70,
     "damage": 120,
     "force": 50,
     "damage_type": "����",
]),
});

int valid_learn(object me)
{
    object ob;
    
//if (me->query("family/family_name") != "�ݿ�ɽ�޵׶�")
//return notify_fail("�㻹δϰ��Ѫ�ȣ��޷�ѧ���޽���\n")
    if ((int)me->query("max_force") < 100)
   return notify_fail("����������㣬�������򽣷��ľ���֮����\n");
    
    if (!(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
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
m_actions=me->query("skill_qixiu-jian");
i=me->query_action("QXJ_perform");
if(!me->query_temp("QXJ_perform")) {
if(me->query("skill_qixiu-jian")==0)
return action[random(5)];
if(random(2)) return action[random(5)];
return m_actions[random(sizeof(m_actions))];
} else {
return action[6];
}
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
 //if (me->query("family/family_name") != "�ݿ�ɽ�޵׶�") 
// return notify_fail("�㻹δϰ��Ѫ�ȣ��޷������޽���\n")
    if ((int)me->query("kee") < 30)
   return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
    if ((int)me->query("force") < 5)
   return notify_fail("�������������û�а취�������޽���\n");
    me->receive_damage("kee", 30);
   me->add("force", -5);
//    write("�㰴����ѧ����һ�����޽���\n");
    return 1;
}
/*
void set_busy()
{
    object me=this_player();
    me->start_busy(1);
 }
*/
string perform_action_file(string action)
{
return CLASS_D("yaomo") + "/wudidong/qixiu-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("qixiu-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������޽�����������ˣ�������޽�������һ���µľ��磡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����޽��������һ���µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
        return ;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_qixiu-jian");
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
   if(!arg||arg==" ")arg="���޽�����"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIG"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qixiu-jian",m_actions);
}
