//hongtianza.c �������ҡ�
//Modified by Venus Oct.1997
//Changed by wuyou@sk

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,*limbs;
        int i,size,damage;
        object my_w,target_w;
        my_w = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á������ҡ���\n");
        if(target->query_temp("weapon"))
                target_w = (object)target->query_temp("weapon");
        if( target->is_busy())
                return notify_fail(target->name() + "Ŀǰ��ãȻ��֪���룬�ӽ������ɡ�\n");
        if( (int)me->query_skill("kaishan-chui",1) < 50)
                return notify_fail("��Ŀǰ������ʹ�����������ҡ���\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n");
        me->add("force", -60);
        msg = WHT"$NͻȻ����һ�����������ң��������о޴���Ȼ����$p���б��У�\n"NOR;
        me->start_busy(1);

        if (target->query_temp("weapon") ||
        target->query_temp("secondary_weapon")) 
        {

                if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
                {
                        if( target_w->weight() > 2 * random(my_w->weight()) ) 
                        {
                                msg += MAG"���$p���е�"+target_w->query("name")+"��$P�ĺ������Ҹ����ţ���Ҳ���ղ�ס���������ַɳ���\n" NOR;
                                target_w->unequip();
                                target_w->move(environment(target));
                                target->reset_action();
                                target->start_busy( (int)me->query_skill("kaishan-chui") / 20 );
                        }
                        msg += HIC "ֻ��$n���е�"+target_w->query("name")+"��Ȼ���Ҷ������Σ�����
�ܵ�$N�ľ����ļ�������$nѸ����ȥ��\n"NOR;
                        message_combatd(msg,me,target,"");
                        target_w->unequip();
                        target_w->move(environment(target));
                        target_w->set("name", target_w->query("name") + "����Ƭ");
                        target_w->set("value", target_w->query("value")/10);
                        target_w->set("weapon_prop", 0);
                        target->reset_action();
                        target->start_busy( (int)me->query_skill("kaishan-chui") / 20 );
                        limbs=target->query("limbs");
                        me->start_busy(2);
                        msg += HIC"���$p���������������˸����ֲ�����\n" NOR;
                        size=(int)(me->query_skill("kaishan-chui")/5);
                        damage=random(size)+size;
                        damage=damage+me->query_str()+random(me->query_temp("apply/damage"));
                        for(i=0;i<=random(size);i++)
                        {
                                msg =HIG"���͡�����Ƭ����$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
                                message_combatd(msg,me,target,"");
                                target->receive_damage("kee",damage,me,"pfm");
                                target->receive_wound("kee",damage,me,"pfm");
                        }
                        COMBAT_D->report_status(target);
                } 
                else 
                {
                        msg += "����$p��æ���Լ��ı�����������û����$P�ļ�ı�óѡ�\n" NOR;
                        me->start_busy(3);
                }
                return 1;
        }
        return notify_fail(target->name() + "Ŀǰ�ǿ��֣�������ʲô��\n");
}


