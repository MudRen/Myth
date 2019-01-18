#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����޸��衹��\n");
        if(!me->is_fighting())
                return notify_fail("�����޸��衹ֻ����ս����ʹ�ã�\n");
        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("�������޵ظ��Ĳ����á����޸��衹��\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("hellfire-whip", 1) < 60)
                return notify_fail("����һ����Ϊ��������ʹ����һ�л������ѣ�\n");
        msg = HIR"\n$N����ζ��缲�磬�Լ�����ٶ�˲������$nת�˾�ǧ�Űپ�ʮ��Ȧ,ͻȻ���һ�ޣ�\n"NOR;
        ap = me->query("combat_exp"); 

        dp = target->query("combat_exp"); 

        if( random(ap)> (dp/4)) 
        {
                damage = me->query_skill("whip",1) * 2 + me->query("force_factor");
                if (damage > 1000) damage = 900+random(100);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                msg += CYN"���$n��$N�ġ����޸��衹�Ի�δ�ܶ�����\n"NOR;
        }
        else 
                msg += "���Ǳ�$n�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-200);
        me->start_busy(2);
        return 1;
}

