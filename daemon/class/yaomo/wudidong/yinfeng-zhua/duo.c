//Cracked by Roath
// duo.c ���������
//pudding 99.12 

#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( (int)me->query_temp("duo") )
                return notify_fail("���Ѿ��ڶ���˵ı����ˡ�\n");
        skill = me->query_skill("yinfeng-zhua",1);

        if( !(me->is_fighting() ))
                return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("�������֡�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

        if( skill < 50)
                return notify_fail("�������צ�ȼ�����, ���ܿ�������У�\n");

        if( me->query("force") < 200 )
                return notify_fail("��������������޷���������У�\n");
 
        msg = CYN "$N�����Ϣ������ʩչ��������еľ���. \n";
        message_vision(msg, me);
 
        dp = target->query_skill("parry") * 2 / 3;
        if( dp < 1 )
                dp = 1;
        if( random(skill) > dp )
        {
                if(userp(me))
                        me->add("force",-80);
                msg = "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����\n" NOR;
                target->start_busy(2);
                weapon2->move(me);
                me->start_busy(random(2));
        }
        else
        {
                msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
                me->start_busy(random(3));
        }
        message_vision(msg, me, target);

        return 1;
}

