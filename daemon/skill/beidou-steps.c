// Beidou-steps.c  ����ת����Ų�ƴ󷨡�
// BY Cigar 2002.04.19
inherit SKILL;

string *dodge_msg = ({
        "$nһ�С���������Ϸ���ǡ��������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ������Ҳ�̤�ǳ������ѱ����߳�֮�⡣\n",
        "$nʹ������ת���������ֻء����������ɵ�������\n",
        "$n����һ�㣬һ�С�Ų����Ӱ����ת���ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С��綯����ǳ��项����������Ʈ�˿�ȥ��\n",
        "$n��Ӱ΢�����Ѿ���һ�С���������������������������\n",
        "����$nһ�С������������յ���ʹ���������Ƶ�$N���ᣡ\n"
        "$n���ζ��ر��Ʈ����������$N�޷����塣\n",
        "$n˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
        "$n��һ����磬�滺��������$N���������ơ�\n",
        "$n������ͥ�Ų����ڵ�ָ����Ȼ�˳����⡣\n",
        "����$n��һת����һ�ƣ���Ӱ����ʧ������\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����ת����Ų�ƴ󷨡�\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
              if (me->query("class") != "lunhui") 
                      return notify_fail("���������������ת����Ų�ƴ󷨣�\n"); 
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�������������������������ת����Ų�ƴ󷨡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

/*
      mapping query_action(object me, object weapon) 
      { 
       int i; 
       mapping* m_actions; 
       i=me->query_action("beidou_perform"); 
       if( ! me->query_temp("beidou_perform")) 
            { 
           if(me->query("skill_beidou-steps")==0) return action[random(5)]; 
           if(random(2))return action[random(5)]; 
           m_actions=me->query("skill_beidou-steps"); 
           return m_actions[random(sizeof(m_actions))]; 
            } 
          else  
         { 
        return action[5]; 
        } 
         return action[random(sizeof(action))]; 
      }
*/
string perform_action_file(string action)
{
        return CLASS_D("lunhui") + "/beidou-steps/" + action;
}
