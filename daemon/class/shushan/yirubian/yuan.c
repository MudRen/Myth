//yuan.c... by koker 2001.03.21

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
                return notify_fail("��Ҫ��˭ʩչ����Թ�޻ڡ���\n");
        if(!me->is_fighting())
                return notify_fail("����Թ�޻ڡ�ֻ����ս����ʹ�ã�\n");
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("������ɽ���ɵĲ����á���Թ�޻ڡ���\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("yirubian", 1) < 70)
                return notify_fail("�������޷�������տ��ʹ����һ�л������ѣ�\n");

        msg = HIR"\n$N�����̾�˿��������еĳ���������л��˸�Ȧ��ͻȻ����ֱ��$n��\n"NOR;
        ap = me->query_skill("whip");
        ap = ap*ap*ap / 20;
        dp = target->query("combat_exp"); 
        chance = (int)(random( ap + dp ) / dp * 100);
        if (target->is_busy()) chance *= 3;
        if( chance > 26 ) 
        {
                damage = me->query_skill("whip") * 2 + me->query("force_factor");
                if (damage > 800) damage = 750+random(75);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm");
                target->start_busy(random(2)+3);
                msg += CYN"���$n��$N�ġ���Թ�޻ڡ�����������\n"NOR;
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
        me->add("force",-200-me->query("force_factor"));
        me->start_busy(2);
        return 1;
}

