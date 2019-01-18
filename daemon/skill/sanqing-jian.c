
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

// sanqing-jian.c�����彣����
//for ��ʿ NPCs, if going to be used by players, need refine. 

/*
���彣��    dodge  -5    parry  15    damage  20
���ҹ�������Ʈ�ݣ���մ����֮������Ψ��̫������
����̫ʵ�á�
*/
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N���쳤Ц����Ҳ������һ��",
        "$N����һԾ��ʹ�˸�",
        "$N��̬���У�һ��",
        "$N����ת����ͣ��ͻȻһ��",
        "$N����̤�˸����ǲ���һ��",
});

string* skill_tail =({
        "������$w����������$n����һն",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "�����ֶ�׼$n$lһ����ȥ",
        "����$nת��֮�ʣ��ӳ�һ��",
});



mapping *action = ({
   ([   "action":     "$Nʹ��һ��"+BLINK""+HIR"���Ǻ�Ӱ����"NOR+"��������˸�������������޵ش���$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����ת����ͣ��ͻȻһ��"+BLINK""+HIY"��һ����Ϭ��"NOR+"ʹ��������$w����һ������������$n$l",
     "dodge":     -10,
     "parry":     15,
     "damage":     45,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����̤�˸����ǲ���һ��"+BLINK""+HIM"���ŵ����硹"NOR+"����$w����������$n����һն",
     "dodge":     -5,
     "parry":     15,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":     "����$N���˼�������Ȼ������Ծ������$wһʽ"+BLINK""+HIW"���׺�������"NOR+"��׼$n��$l���һն",
     "dodge":     -15,
     "parry":     5,
     "damage":     50,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����һԾ��ʹ�˸�"+BLINK""+HIB"���˷��ȥ��"NOR+"��ȴ��ת��֮�ʶ�׼$n$lбб�ӳ�һ��",
     "dodge":     5,
     "parry":     25,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��̬���У�����$wƾ��һָ��һ��"+BLINK""+HIC"������ǧ�ء�"NOR+"����ػ���$n��$l",
     "dodge":     -10,
     "parry":     10,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����$w����һ�֣�ʹһ��"+BLINK""+HIG"������ͨ�ġ�"NOR+"���ֶ�׼$n$lһ����ȥ",
     "dodge":     0,
     "parry":     20,
     "damage":     35,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail("�������������û�а취�����彣����\n");

   if( !(ob = me->query_temp("weapon"))
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
     mapping* m_actions;
     m_actions=me->query("skill_sanqing-jian");
     if(me->query("skill_sanqing-jian")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 100
   ||   (int)me->query("force") < 30 )
     return notify_fail("�����������������û�а취��ϰ���彣����\n");
   me->receive_damage("kee", 32);
   me->add("force", -6);
//   write("�㰴����ѧ����һ�����彣����\n");
   return 1;
}
string perform_action_file( string action)
{
     return CLASS_D("zhenyuan") + "/sanqing-jian/"+ action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������彣����������ˣ�������彣������һ���µľ��磡\n"NOR);

//     if(random(me->query("kar"))<20){
//        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
//        return;
//     }
//     if(random(me->query("int"))<20){
//       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
//       return;
//     }
     tell_object(me,HIW"��ͻȻ�������飬�����彣�������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_sanqing-jian");
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

   if(!arg||arg==" ")arg="���彣����"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIB"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
}
 
