// shendao.c stey Ѫ������Ѫ�񵶡�

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail(RED"װ��������ʹ�á��ݹǼ�Ѫ�񵶡���\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���ݹǼ�Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("kugu-blade", 1) < 200 )
                return notify_fail(WHT"��ݹǵ�����������죬ʹ�������ݹǼ�Ѫ�񵶡���\n"NOR);
        if ((int)me->query_skill("huntian-qigong", 1) < 200 )
                return notify_fail(RED"�����������򲻹���ʹ�������ݹǼ�Ѫ�񵶡���\n"NOR);
        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("ֻ���޵׶����˲ſ����ã�\n");
        if ((int)me->query("max_force") < 600)
                return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
        if ((int)me->query("force") < 600)
        {
                return notify_fail(HIC"����������������û�ܽ����ݹǼ�Ѫ�񵶡�ʹ�꣡\n"NOR);
        }
        msg = HIC "$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ��
��ס��Ӱ��$n��ͷ���䣬\n"NOR;

        if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/2) > (int)target->query("combat_exp")*1/2 ))) 
        {
                //damage = random((int)(me->query("sen")/2))+(int)(me->query("sen")/30);
                damage = random((int)(me->query("sen")/10))+(int)(me->query("sen")/2);
                me->add("force", -200);
                me->recevive_damage("kee", (me->query("kee")/10), me, "pfm");
                me->start_busy(1);
                target->start_busy(2+random(2));
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                msg += HIC"$n��æ������ã���Ѫ��������ֻ����ǰһ��Ѫ�죬����������£���Ѫ��
���������󺿣�\n"NOR;
                if(me->query_temp("wddtoppfm"))
                {
                        msg+=HIG"$Nʹ���񵶾�����������ѪӰ��\n$nһʱ�����ӱ����У�������Ѫɫ������У��ܵ�����ֲ����˺���\n";
                        target->receive_damage("kee", damage*(random(4)+1), me, "pfm");
                }
        } 
        else
        {
                me->start_busy(2);
                me->add("kee", -(me->query("kee")/7));
                msg += HIY"����$n������ã����Ĳ�æ�������$N��Ѫ����\n"NOR;
                me->add("force", -120);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

