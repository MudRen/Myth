// sandu.c ����צɢ�� edited by stey

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��ɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ�ܹ�������! \n");

        if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/2 )
                return notify_fail("������ɢ����û�õġ�\n");

        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("ֻ���޵׶����˲ſ����ã�\n");
                
        if( (int)me->query_skill("huntian-qigong", 1) < 180 )
                return notify_fail("��Ļ��������󷨲�����죬����ɢ����\n");

        if( (int)me->query_skill("yinfeng-zhua", 1) < 180 )
                return notify_fail("�������צ������죬����ɢ����\n");

        msg = GRN "ֻ����$N�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n��
�󣬽������������ģ�ԴԴ���ϴ���$n���ڡ�\n";

        me->start_busy(1);
        if( random( (int)me->query_skill("yinfeng-zhua",1)) > random(target->query_skill("dodge") /2 ) ) 
        {
                msg += CYN " ���$p����������$P�ı�����������ɢ��$n���ڣ�\n" NOR;
                target->receive_damage("kee", 200, me, "pfm");
                target->receive_wound("kee", 100 + random(80), me, "pfm");
                target->apply_condition("poison_sandu", 1000);
                me->clear_condition();
                target->start_busy(random(2));
        } 
        else 
        {
                msg += YEL"����$p������������һ�𣬽�$N�������˿�ȥ��\n" NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

