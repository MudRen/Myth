// ghost-dodge.c ��Ӱ���ٲ���
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({

"$n���ƹ��ȣ��㲻�����Ȳ�̧����ȻƮȻ���𣬾�Ȼ���赭д�ܹ���$N���С�\n\n",

"$Nһ�л��������ƴ�����ţ�ȴ����$n����ͻȻ��ʧ��һ��ͷ�����־�Ȼ�������\n\n",

"ֻ��$n�Ų�ɢ�ң������һΣ�$N��ǰ��ʱֻʣһ�Ź�Ӱ����֪��ι�����\n\n" ,

"$nͻȻ�ӿ첽��������һ��������$N��ǰ������������ߣ�$N�ۻ�����������ա�\n\n",

"$n�����Ц�����徹��ȫ�����������Ʊ����У�ȴ��$N��ʽƮ������δ��һ˿�˺���\n\n",

"$nϥ�ǲ��䣬ֱ��ֱ�µ����������Ƽ���׾��ȴ����׾ٵض㿪��$N�Ĺ�����\n\n" NOR });


int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 40)
                return notify_fail("�������̫���ˣ���������Ӱ���١�\n");
        me->receive_damage("kee", 30);
        return 1;
}

