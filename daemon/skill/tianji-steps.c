inherit SKILL;
string *dodge_msg = ({
     "��һ�С�����Ҳ�������$N�ֵ��Ǳ�������\n",
     "$n����һ�㣬һ�С��������ࡹ�ڿն��𣬱��˿�ȥ��\n",
     "����$n�ظ�����һ�����ڼ䲻�ݷ�֮��һ������ת��Ȩ������������\n",
     "$n��������ʹ��������������$Nֻ������һ������ʧ$n����Ӱ��\n",
     "$n�������ˣ�����ֻ������һת��һʽ����Ӱ���ࡹ����һ�л�Ӱ��$N����ӹ���\n",
     "$n�ƺ��е������������æ֮��ʹ��һʽ���������١���$N��ǰ���һ������֪���ľ��˿��ˡ�\n",
     "ֻ��$n˳��һ�ƣ�����һ�ɼ��磬�������ڷ����\n$N�Ĺ�����ʧ��׼ͷ�����ǡ�����������еġ��綯��⡹��\n"
});

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("�������̫���ˣ����������������\n");
        me->receive_damage("kee", 30);
        return 1;
}

