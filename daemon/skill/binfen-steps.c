// binfen-steps.c �ͷײ���
// edited by mind

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
        "$nһ��"+RED"�����մ߻�ů��Ȼ��"NOR+"�������̻��������ɵر��˿�ȥ��\n",
        "ֻ��$n��һ��������һʽ"+MAG"���ճ������ɡ�"NOR+"���ѱ����߳�֮�⡣\n",
        "$nʹ��"+HIC"���������������ȡ�"NOR+"���������ɵ�������\n",
        "$n����һ�㣬һ��"+HIW"������ü��Զ��ܡ�"NOR+"�������������˿�ȥ��\n",
        "����$nʹһ��"+HIY"����Ӣ�����ԵͰ���"NOR+"����������Ʈ�˿�ȥ��\n",
        "$n��Ӱ��չ���Ѿ���һ��"+HIG"������̽���污�"NOR+"�Ի��$N�����Ա���\n",
        "����$nһ��"+HIW"�������������ܻ���"NOR+"ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 10 )
                return notify_fail("�������������û�а취���ͷײ�����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("������������������������ͷײ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}



