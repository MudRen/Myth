//Cracked by Roath

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("gouhunshu",1) < 100 )
                return notify_fail("��Ĺ����������ߣ�\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����ɢ��\n");

        if((int)me->query("kee") < 25 )
                return notify_fail("�����Ѫ������\n");

        me->receive_wound("kee", 25);
        msg = HIC "$N���в��ϵ��������ģ�ֻ��������ͣ����$n��ȥ��\n\n" NOR;

        ap = me->query_skill("gouhunshu");
        extradam = ap/2;
        ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) 
        {
                damage = me->query("bellicosity") /50 ;
                msg +=  RED "�����𽥰�Χ��$p������!\n" NOR;
                message_vision(msg, me, target);
                if (damage > 1000) damage = 975 + random(50);
                target->receive_damage("kee", damage, me, "cast");
                target->receive_wound("kee", damage/3, me, "cast");
                if( damage > 0 ) COMBAT_D->report_status(target);

        } 
        else
        {
                msg += "���Ǳ�$n�����ˣ���\n";
                message_vision(msg, me, target);
        }
        if( !target->is_fighting(me) )  
        { 
                if( living(target) )  
                { 
                        if( userp(target) ) target->fight_ob(me); 
                        else me->kill_ob(target); 
                } 
        } 

        me->start_busy(2);
        return 1;
}

