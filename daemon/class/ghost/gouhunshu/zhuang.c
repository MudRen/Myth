// write by stey

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("�ǹ��岻��ʹ��\n");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչԪ��ײ��\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷��ֳ�Ԫ���ײ���ˣ�\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIC
"$N�������˼������ģ�ͻȻ�������һ���������Լ���Ԫ��վ��ԭ����λ���ϡ�\n
ֻ��$N��Ԫ��һ�沿������������֣�¶��һ�����˿ֲ�����ɫ����\n
���š�໡���һ������޺�$N��Ԫ��ֱֱ����$n��\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) 
        {
                damage = (int)me->query("max_mana") / 10 +
                random((int)me->query("eff_sen") / 10);
                damage -= (int)target->query("max_mana") / 10 +
                random((int)target->query("eff_sen") / 10);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
                if( damage > 0 ) 
                {
                        damage +=damage+random((damage*(int)me->query_skill("spells"))/200);
                        msg += HIR "���$n��$N��Ԫ����������������ŵò��Ҷ�����
��ײ�÷��˳�ȥ��\n$N��Ԫ���ֻص�$N�������\n" NOR;
                        target->receive_damage("sen", damage, me, "cast");
                        target->receive_wound("sen", damage/2, me, "cast");
                        target->receive_damage("kee", damage*2/3, me, "cast");
                        target->receive_wound("kee", damage/5, me, "cast");
                        me->improve_skill("gouhunshu", 1, 1);
                }
                else 
                {
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note, damage<0.
                        msg += HIR "$n����$N��Ԫ��ӭ����˹��������Ǵ����һ����
\n˭֪��һ�޺�Ȼ��$N��Ԫ���ɢ����ʧ����Ӱ�����ˡ�\n$N��ʱ������Ѫ�����˴�Ԫ��
��$N��Щ�������ˡ�\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target, "cast");
                        me->receive_wound("sen", -damage/2, target, "cast");

                        me->improve_skill("gouhunshu", 1, 1);
                }
        }
        else
                msg += "$n����ͷ���ã���������㿪�˹�����\n$N��Ԫ���ֻص���$N��
�����\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "���Ǳ�$n�㿪�ˡ�\n"--no report.

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
                        me->kill_ob(target);
                }
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

